/************************************************************************************
 * Module		: LED Driver
 * File Name	: led.c
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: Source file for the LED Driver
 ************************************************************************************/
#include "led.h"

static LED_Logic g_ledLogic = POSITIVE_LOGIC;	/* Default logic */

void LEDS_init(void)
{
	/* Set LED pins as output */
	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);

	/* Turn off all LEDs */
	LED_off(LED_RED);
	LED_off(LED_GREEN);
	LED_off(LED_BLUE);
}

void LED_on(LED_ID id)
{
	if (POSITIVE_LOGIC == g_ledLogic)
	{
		switch (id)
		{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_HIGH);
			break;
		case LED_GREEN:
			GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_HIGH);
			break;
		case LED_BLUE:
			GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_HIGH);
			break;
		}
	}
	else if(NEGATIVE_LOGIC == g_ledLogic)
	{
		switch (id)
		{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
			break;
		case LED_GREEN:
			GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
			break;
		case LED_BLUE:
			GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
			break;
		}
	}
}

void LED_off(LED_ID id)
{
	if (NEGATIVE_LOGIC == g_ledLogic)
	{
		switch (id)
		{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_HIGH);
			break;
		case LED_GREEN:
			GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_HIGH);
			break;
		case LED_BLUE:
			GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_HIGH);
			break;
		}
	}
	else if(POSITIVE_LOGIC == g_ledLogic)
	{
		switch (id)
		{
		case LED_RED:
			GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
			break;
		case LED_GREEN:
			GPIO_writePin(LED_GREEN_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
			break;
		case LED_BLUE:
			GPIO_writePin(LED_BLUE_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
			break;
		}
	}
}

 void LED_setLogic(LED_Logic logic)
 {
	 g_ledLogic = logic;
 }
