/************************************************************************************
 * Module		: DC Motor Driver
 * File Name	: dc_motor.c
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: Source file for the DC Motor Driver
 ************************************************************************************/
#include "dc_motor.h"

void DC_Motor_Init(void)
{
	/* Set motor pins as output */
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT_ID, DC_MOTOR_ENABLE_PIN_ID, PIN_OUTPUT);

	/* Stop the motor initially */
	DC_Motor_Rotate(DC_MOTOR_STOP, 0);
}

void DC_Motor_Rotate(DC_Motor_State state, uint8 speed)
{
	GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_ENABLE_PIN_ID, LOGIC_HIGH);

	switch (state)
	{
	case DC_MOTOR_CW:
		/* Rotate clockwise */
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID, LOGIC_LOW);
		PWM_Timer0_setDutyCycle(speed); /* Set speed using PWM */
		break;

	case DC_MOTOR_ACW:
		/* Rotate anti-clockwise */
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID, LOGIC_HIGH);
		PWM_Timer0_setDutyCycle(speed); /* Set speed using PWM */
		break;

	case DC_MOTOR_STOP:
		/* Stop the motor */
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN1_ID, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT_ID, DC_MOTOR_PIN2_ID, LOGIC_LOW);
		PWM_Timer0_setDutyCycle(0); /* Set speed to 0 */
		break;
	}
}
