/************************************************************************************
 * Module		: Smart Home Automation
 * File Name	: Smart_Home_Automation.c
 * Author		: Mahmoud 3smat
 * Created on	: 7/10/2024
 * Description	: Main application file for the smart home automation system
 ************************************************************************************/
#include "Smart_Home_Automatio.h"

static uint8 g_temperature = 0;
static uint8 g_lightIntensity = 0;
static uint8 g_flame_flag = 0;

int main(void)
{
	/******************************** Initialize components ********************************/
	FlameSensor_init();
	PWM_Timer0_Init(0);
	DC_Motor_Init();
	Buzzer_init();
	LEDS_init();
	LCD_init();

	LCD_clearScreen();

	while (1)
	{
		/************************* Get temperature and light intensity ************************/
		g_temperature = LM35_getTemperature();
		g_lightIntensity = LDR_getLightIntensity();

		/* Display current temperature and light intensity on LCD */
		LCD_displayStringRowColumn(0, 0, "FAN is ");
		if (25 <= g_temperature)
		{
			LCD_displayStringRowColumn(0, 7, "ON ");
		}
		else
		{
			LCD_displayStringRowColumn(0, 7, "OFF");
		}

		LCD_displayStringRowColumn(1, 0, "Temp:");
		LCD_intgerToString(g_temperature);
		LCD_displayString("C LDR:");
		LCD_intgerToString(g_lightIntensity);
		LCD_displayString("% ");

		/************************* Control LED based on light intensity ************************/
		if (15 > g_lightIntensity)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_on(LED_BLUE);
		}
		else if (15 <= g_lightIntensity && 50 >= g_lightIntensity)
		{
			LED_on(LED_RED);
			LED_on(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else if (50 < g_lightIntensity && 70 >= g_lightIntensity)
		{
			LED_on(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}
		else
		{
			LED_off(LED_RED);
			LED_off(LED_GREEN);
			LED_off(LED_BLUE);
		}

		/************************ Control fan speed based on temperature ************************/
		LCD_displayStringRowColumn(0, 10, "(");
		if (40 <= g_temperature)
		{
			LCD_displayString("100%)");
			DC_Motor_Rotate(DC_MOTOR_CW, 100); /* Rotate clockwise at 100% speed */
		}
		else if (35 <= g_temperature)
		{
			LCD_displayString("75%) ");
			DC_Motor_Rotate(DC_MOTOR_CW, 75); /* Rotate clockwise at 75% speed */
		}
		else if (30 <= g_temperature)
		{
			LCD_displayString("50%) ");
			DC_Motor_Rotate(DC_MOTOR_CW, 50); /* Rotate clockwise at 50% speed */
		}
		else if (25 <= g_temperature)
		{
			LCD_displayString("25%) ");
			DC_Motor_Rotate(DC_MOTOR_CW, 25); /* Rotate clockwise at 25% speed */
		}
		else if (25 > g_temperature)
		{
			LCD_displayString("0%)  ");
			DC_Motor_Rotate(DC_MOTOR_STOP, 0); /* Stop the motor */
		}
		/****************************** Check for fire detection *****************************/
		if(FlameSensor_getValue())
		{
			g_flame_flag = 1;
			LCD_clearScreen();
			while (FlameSensor_getValue() && (1 == g_flame_flag))
			{
				Buzzer_on(); /* Activate buzzer */
				LCD_displayStringRowColumn(0, 0, "Critical Alert!");
				DC_Motor_Rotate(DC_MOTOR_STOP, 0); /* Ensure motor is stopped during alert */
			}
		}
		else if(1 == g_flame_flag)
		{
			LCD_clearScreen();
			Buzzer_off(); /* Turn off buzzer */
			g_flame_flag = 0;
		}
		else
		{
			Buzzer_off(); /* Turn off buzzer */
		}
	}
}
