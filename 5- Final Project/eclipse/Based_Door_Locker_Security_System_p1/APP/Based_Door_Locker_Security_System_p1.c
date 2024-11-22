/************************************************************************************
 * File Name	: Based_Door_Locker_Security_System_p1.c
 * Author		: Mahmoud 3smat
 * Created on	: 26/10/2024
 * Description	: Source file for the application
 ************************************************************************************/
#include "Based_Door_Locker_Security_System_p1.h"

/* Global variables for password storage, state flags, and timer ticks */
uint8 password[PASSWORD_LENGTH];		/* Array to store the main password */
uint8 password_confirm[PASSWORD_LENGTH];	/* Array to store the confirmed password */
uint8 g_tick = 0;		/* Timer tick counter */
uint8 g_flag = 0;		/* Flag to indicate if password is set */
uint8 g_status_flag;	/* Flag to check password status */

int main(void)
{
	UART_init(BOUD_RATE);	/* Initialize UART communication */
	LCD_init();		/* Initialize the LCD display */

	SREG |= (1 << 7);	/* Enable global interrupts */

	/* Main application loop */
	while (1)
	{
		if (g_flag == 0)
		{
			Step1_CreatePassword();	/* Prompt for password creation */
		}
		else
		{
			Step2_MainOptions();	/* Show main options if password is set */
		}
	}
}

void Step1_CreatePassword(void)
{
	LCD_clearScreen();
	LCD_displayString("PLZ enter Pass:");
	LCD_moveCursor(1, 0);
	receivePassword(password);	/* Get the password from the user */

	UART_sendByte(HMI_ECU_READY);
	transmittePassword(password);	/* Send the password to the Control ECU */

	LCD_clearScreen();
	LCD_displayString("PLZ re-enter");
	LCD_displayStringRowColumn(1, 0, "same pass:");
	LCD_moveCursor(1, 10);
	receivePassword(password_confirm);	/* Confirm the password */

	UART_sendByte(HMI_ECU_READY);
	transmittePassword(password_confirm);	/* Send the confirmed password */

	/* Wait for the Control ECU to be ready and check password status */
	while (UART_recieveByte() != CONTROL_ECU_READY);
	g_status_flag = UART_recieveByte();

	/* Check if passwords match and update the flag */
	if (g_status_flag == PASSWORD_MATCHED)
	{
		LCD_clearScreen();
		LCD_displayString("Password Stored");
		_delay_ms(500);
		g_flag = 1;	/* Password set successfully */
	}
	else
	{
		LCD_clearScreen();
		LCD_displayString("Pass UnMatched");
		_delay_ms(500);
		g_flag = 0;	/* Password not set, stay in the loop */
	}
}

void Step2_MainOptions(void)
{
	uint8 choice = 0;	/* Variable for user choice */

	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "+ : open Door");
	LCD_displayStringRowColumn(1, 0, "- : change pass");

	choice = KEYPAD_getPressedKey();	/* Get user choice from keypad */
	_delay_ms(200);	/* Debounce delay */

	/* Execute action based on user choice */
	switch (choice)
	{
	case '+':
		Step3_UnlockDoor();	/* Open door option */
		break;
	case '-':
		Step4_ChangePassword();	/* Change password option */
		break;
	}
}

void Step3_UnlockDoor(void)
{
	uint8 PIR_flag = 0;	/* Flag for PIR sensor detection */
	uint8 count;

	/* Allow a maximum number of tries to unlock the door */
	for (count = 0; count < MAX_TRY_COUNTER; count++)
	{
		UART_sendByte(HMI_ECU_READY);
		UART_sendByte(0);	/* Request to open the door */

		LCD_clearScreen();
		LCD_displayString("Enter Pass:");
		LCD_moveCursor(1, 0);
		receivePassword(password);	/* Get password for unlocking */

		UART_sendByte(HMI_ECU_READY);
		transmittePassword(password);	/* Send password to Control ECU */

		/* Check if the password matches */
		while (UART_recieveByte() != CONTROL_ECU_READY);
		g_status_flag = UART_recieveByte();

		if (g_status_flag == PASSWORD_MATCHED)
		{
			LCD_clearScreen();
			LCD_displayString("Door Unlocking");
			LCD_displayStringRowColumn(1, 2, "Please wait");

			/* Wait for PIR sensor status */
			while (UART_recieveByte() != CONTROL_ECU_READY);
			PIR_flag = UART_recieveByte();	/* Get PIR sensor status */

			/* If motion is detected, wait for people to enter */
			if (1 == PIR_flag)
			{
				LCD_clearScreen();
				LCD_displayString("Wait for people");
				LCD_displayStringRowColumn(1, 2, "To Enter");
				while (UART_recieveByte() == 1);
				PIR_flag = 0;
			}
			Timer_setCallBack(timer_increase_ticks, TIMER1);
			Timer_init(&timer1_configurations);	/* Initialize the timer */

			LCD_clearScreen();
			LCD_displayString("Door is locking");
			g_tick = 0;	/* Reset tick counter */
			while (g_tick < 15);	/* Wait for 15 seconds */
			Timer_deInit();	/* Deinitialize the timer */
			break;
		}

		UART_sendByte(HMI_ECU_READY);
		UART_sendByte(1);	/* To continue */
	}

	if (g_status_flag == PASSWORD_UNMATCHED)
	{
		Step5_UnmatchedPasswordHandling();	/* Handle unmatched password */
	}
}

void Step4_ChangePassword(void)
{
	uint8 count;
	/* Allow a maximum number of tries to change the password */
	for (count = 0; count < MAX_TRY_COUNTER; count++)
	{
		UART_sendByte(HMI_ECU_READY);
		UART_sendByte(1);	/* Request to change password */

		LCD_clearScreen();
		LCD_displayString("Enter old Pass:");
		LCD_moveCursor(1, 0);
		receivePassword(password);	/* Get the old password */

		UART_sendByte(HMI_ECU_READY);
		transmittePassword(password);	/* Send old password to Control ECU */

		/* Check if the old password matches */
		while (UART_recieveByte() != CONTROL_ECU_READY);
		g_status_flag = UART_recieveByte();

		if (g_status_flag == PASSWORD_MATCHED)
		{
			UART_sendByte(HMI_ECU_READY);
			UART_sendByte(0);	/* Restart the password setting process */
			g_flag = 0;	/* Reset the password flag */
			break;
		}

		UART_sendByte(HMI_ECU_READY);
		UART_sendByte(1);	/* To continue */
	}

	if (g_flag != 0)
	{
		Step5_UnmatchedPasswordHandling();	/* Handle unmatched password */
	}
}

void Step5_UnmatchedPasswordHandling(void)
{
	Timer_setCallBack(timer_increase_ticks, TIMER1);
	Timer_init(&timer1_configurations); 	/* Initialize the timer */

	LCD_clearScreen();
	LCD_displayStringRowColumn(0, 0, "System Locked");
	LCD_displayStringRowColumn(1, 0, "for 1 min.");

	g_tick = 0;	/* Reset tick counter */
	while (g_tick < 60);	/* Wait for 60 seconds */
	Timer_deInit();	/* Deinitialize the timer */
}

void transmittePassword(uint8 *pass)
{
	for (uint8 i = 0; i < PASSWORD_LENGTH; i++)
	{
		UART_sendByte(pass[i]);	/* Send each character of the password */
	}
}

void receivePassword(uint8 *password)
{
	uint8 Buffer;	/* Variable to store pressed key */

	for (uint8 i = 0; i < PASSWORD_LENGTH; i++)
	{
		Buffer = KEYPAD_getPressedKey();	/* Get the pressed key */
		password[i] = Buffer;	/* Store the pressed key */
		LCD_displayCharacter('*');	/* Display '*' for privacy */
		_delay_ms(200);		/* Short delay for keypress */
	}
	while (KEYPAD_getPressedKey() != '\r'); /* Wait for enter key */
	_delay_ms(200);	/* Delay for button release */
}

void timer_increase_ticks(void)
{
	g_tick++; 	/* Increment the tick count */
}
