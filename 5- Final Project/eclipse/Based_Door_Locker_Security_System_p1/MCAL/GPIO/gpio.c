/************************************************************************************
 * File Name	: gpio.c
 * Author		: Mahmoud 3smat
 * Created on	: 25/9/2024
 * Description	: GPIO Driver
 ************************************************************************************/
#include "gpio.h"

void GPIO_setupPinDirection(GPIO_PORT_ID port_id, GPIO_PIN_ID pin_id, GPIO_PinDirection direction)
{
	if((NUM_OF_PORTS <= port_id) && (NUM_OF_PINS_PER_PORT <= pin_id))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		if(PIN_OUTPUT == direction)
		{
			switch(port_id)
			{
			case PORTA_ID:
				SET_BIT(DDRA_REG, pin_id);
				break;
			case PORTB_ID:
				SET_BIT(DDRB_REG, pin_id);
				break;
			case PORTC_ID:
				SET_BIT(DDRC_REG, pin_id);
				break;
			case PORTD_ID:
				SET_BIT(DDRD_REG, pin_id);
				break;
			}
		}
		else if(PIN_INPUT == direction)
		{
			switch(port_id)
			{
			case PORTA_ID:
				CLEAR_BIT(DDRA_REG, pin_id);
				break;
			case PORTB_ID:
				CLEAR_BIT(DDRB_REG, pin_id);
				break;
			case PORTC_ID:
				CLEAR_BIT(DDRC_REG, pin_id);
				break;
			case PORTD_ID:
				CLEAR_BIT(DDRD_REG, pin_id);
				break;
			}
		}

	}
}

void GPIO_writePin(GPIO_PORT_ID port_id, GPIO_PIN_ID pin_id, STD_Value value)
{
	if((NUM_OF_PORTS <= port_id) && (NUM_OF_PINS_PER_PORT <= pin_id))
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		if(LOGIC_HIGH == value)
		{
			switch(port_id)
			{
			case PORTA_ID:
				SET_BIT(PORTA_REG, pin_id);
				break;
			case PORTB_ID:
				SET_BIT(PORTB_REG, pin_id);
				break;
			case PORTC_ID:
				SET_BIT(PORTC_REG, pin_id);
				break;
			case PORTD_ID:
				SET_BIT(PORTD_REG, pin_id);
				break;
			}
		}
		else if(LOGIC_LOW == value)
		{
			switch(port_id)
			{
			case PORTA_ID:
				CLEAR_BIT(PORTA_REG, pin_id);
				break;
			case PORTB_ID:
				CLEAR_BIT(PORTB_REG, pin_id);
				break;
			case PORTC_ID:
				CLEAR_BIT(PORTC_REG, pin_id);
				break;
			case PORTD_ID:
				CLEAR_BIT(PORTD_REG, pin_id);
				break;
			}
		}
	}
}

STD_Value GPIO_readPin(GPIO_PORT_ID port_id, GPIO_PIN_ID pin_id)
{
	STD_Value pin_value = LOGIC_LOW;

	if((NUM_OF_PORTS <= port_id) && (NUM_OF_PINS_PER_PORT <= pin_id))
	{
		/* Do Nothing */
	}
	else
	{
		switch(port_id)
		{
		case PORTA_ID:
			pin_value = GET_BIT(PINA_REG, pin_id);
			break;
		case PORTB_ID:
			pin_value = GET_BIT(PINB_REG, pin_id);
			break;
		case PORTC_ID:
			pin_value = GET_BIT(PINC_REG, pin_id);
			break;
		case PORTD_ID:
			pin_value = GET_BIT(PIND_REG, pin_id);
			break;
		}
	}
	return pin_value;
}

void GPIO_setupPortDirection(GPIO_PORT_ID port_id, GPIO_PortDirection direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(NUM_OF_PORTS <= port_id)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch(port_id)
		{
		case PORTA_ID:
			DDRA_REG = direction;
			break;
		case PORTB_ID:
			DDRB_REG = direction;
			break;
		case PORTC_ID:
			DDRC_REG = direction;
			break;
		case PORTD_ID:
			DDRD_REG = direction;
			break;
		}
	}
}

void GPIO_writePort(GPIO_PORT_ID port_id, uint8 value)
{
	if(NUM_OF_PORTS <= port_id)
	{
		/* Do Nothing */
	}
	else
	{
		switch(port_id)
		{
		case PORTA_ID:
			PORTA_REG = value;
			break;
		case PORTB_ID:
			PORTB_REG = value;
			break;
		case PORTC_ID:
			PORTC_REG = value;
			break;
		case PORTD_ID:
			PORTD_REG = value;
			break;
		}
	}
}
