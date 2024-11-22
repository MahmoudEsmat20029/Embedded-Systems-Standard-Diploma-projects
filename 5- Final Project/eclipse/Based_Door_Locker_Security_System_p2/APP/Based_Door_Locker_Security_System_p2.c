/************************************************************************************
 * File Name	: Based_Door_Locker_Security_System_p2.c
 * Author		: Mahmoud 3smat
 * Created on	: 27/10/2024
 * Description	: Source file for the application
 ************************************************************************************/
#include "Based_Door_Locker_Security_System_p2.h"

/* Global Variables */
uint8 password_confirm[PASSWORD_LENGTH];
uint8 password_stored[PASSWORD_LENGTH];
uint8 password[PASSWORD_LENGTH];

boolean g_status_flag = PASSWORD_UNMATCHED;
uint8 g_flag = 0;
uint8 g_tick = 0;		/* Timer tick counter */

int main(void)
{
	/* Initialize peripherals */
	UART_init(BOUD_RATE);
	PIR_init();
	Buzzer_init();
	DC_Motor_Init();

	SREG |= (1 << 7);	/* Enable global interrupts */

	while (1)
	{
		/* Check the current state flag to determine which step to execute */
		if (g_flag == 0)
		{
			Step1_StorePassword();
		}
		else
		{
			Step2_MainOptions();
		}
	}
}

void Step1_StorePassword(void)
{
	/* Wait for CONTROL_ECU to be ready */
	while (UART_recieveByte() != CONTROL_ECU_READY);
	receivePassword(password); /* Receive password from UART */
	while (UART_recieveByte() != CONTROL_ECU_READY);
	receivePassword(password_confirm); /* Confirm password from UART */

	/* Check if passwords match */
	g_status_flag = Step4_CheckPassword(password, password_confirm);

	if (g_status_flag == PASSWORD_MATCHED)
	{
		/* Send status to CONTROL_ECU */
		UART_sendByte(HMI_ECU_READY);
		UART_sendByte(PASSWORD_MATCHED);
		EEPROM_writeByte(EEPROM_ADDRESS, password, PASSWORD_LENGTH); /* Store password in EEPROM */
		_delay_ms(10);
		g_flag++; /* Move to the next step */
	}
	else if ((g_status_flag == PASSWORD_UNMATCHED))
	{
		/* Send unmatched status to CONTROL_ECU */
		UART_sendByte(HMI_ECU_READY);
		UART_sendByte(PASSWORD_UNMATCHED);
	}
}

void Step2_MainOptions(void)
{
	static uint8 tryCounter = 0; /* Counter for password attempts */
	uint8 choice = 0;

	/* Wait for CONTROL_ECU to be ready */
	while (UART_recieveByte() != CONTROL_ECU_READY);
	choice = UART_recieveByte(); /* Get user choice */
	while (UART_recieveByte() != CONTROL_ECU_READY);
	receivePassword(password); /* Receive entered password */

	/* Read stored password from EEPROM */
	EEPROM_readByte(EEPROM_ADDRESS, password_stored, PASSWORD_LENGTH);
	/* Check if entered password matches stored password */
	g_status_flag = Step4_CheckPassword(password_stored, password);

	/* Send status to CONTROL_ECU */
	UART_sendByte(HMI_ECU_READY);
	UART_sendByte(g_status_flag);

	if (g_status_flag == PASSWORD_MATCHED)
	{
		if (0 == choice) /* Unlock door option */
		{
			Step3_UnlockDoor();
		}
		else if (1 == choice) /* Change password option */
		{
			while (UART_recieveByte() != CONTROL_ECU_READY);
			g_flag = UART_recieveByte(); /* Get the new flag from CONTROL_ECU */
		}
	}
	else
	{
		while (UART_recieveByte() != CONTROL_ECU_READY);
		g_flag = UART_recieveByte(); /* Get the new flag */
		tryCounter++;

		/* Check if maximum tries exceeded */
		if (tryCounter == MAX_TRY_COUNTER)
		{
			tryCounter = 0; /* Reset try counter */
			Step5_UnmatchedPasswordHandling(); /* Handle unmatched password scenario */
		}
	}
}

void Step3_UnlockDoor(void)
{
	uint8 PIR_Flag = 0;

	/* Rotate motor to unlock the door */
	DC_Motor_Rotate(DC_MOTOR_CW, 100);
	Timer_setCallBack(timer_increase_ticks, TIMER1);
	Timer_init(&timer1_configurations);	/* Initialize the timer */

	g_tick = 0;	/* Reset tick counter */
	while (g_tick < 15);	/* Wait for 15 seconds */
	Timer_deInit();	/* Deinitialize the timer */
	DC_Motor_Rotate(DC_MOTOR_STOP, 0); /* Stop motor */

	/* Check PIR sensor state */
	PIR_Flag = PIR_getState();
	UART_sendByte(HMI_ECU_READY);
	UART_sendByte(PIR_Flag);

	while (PIR_Flag == 1) /* Keep motor stopped while motion is detected */
	{
		DC_Motor_Rotate(DC_MOTOR_STOP, 0);
		PIR_Flag = PIR_getState();
		UART_sendByte(PIR_Flag);
		_delay_ms(100);
	}

	/* Rotate motor to lock the door */
	DC_Motor_Rotate(DC_MOTOR_ACW, 100);
	Timer_setCallBack(timer_increase_ticks, TIMER1);
	Timer_init(&timer1_configurations);	/* Initialize the timer */

	g_tick = 0;	/* Reset tick counter */
	while (g_tick < 15);	/* Wait for 15 seconds */
	Timer_deInit();	/* Deinitialize the timer */
	DC_Motor_Rotate(DC_MOTOR_STOP, 0); /* Stop motor */
}

uint8 Step4_CheckPassword(uint8* password, uint8* password_confirm)
{
	/* Check if the passwords match */
	for (uint8 i = 0; i < PASSWORD_LENGTH; i++)
	{
		if (password[i] != password_confirm[i])
		{
			return PASSWORD_UNMATCHED; /* Return unmatched status */
		}
	}
	return PASSWORD_MATCHED; /* Return matched status */
}

void Step5_UnmatchedPasswordHandling(void)
{
	/* Activate buzzer for 1 minute on password mismatch */
	Buzzer_on();
	Timer_setCallBack(timer_increase_ticks, TIMER1);
	Timer_init(&timer1_configurations);	/* Initialize the timer */

	g_tick = 0;	/* Reset tick counter */
	while (g_tick < 60);	/* Wait for 1 minute */
	Timer_deInit();	/* Deinitialize the timer */
	Buzzer_off();
}

void receivePassword(uint8* password)
{
	/* Receive password from UART */
	for (uint8 i = 0; i < PASSWORD_LENGTH; i++)
	{
		password[i] = UART_recieveByte();
	}
}

void timer_increase_ticks(void)
{
	g_tick++; 	/* Increment the tick count */
}
