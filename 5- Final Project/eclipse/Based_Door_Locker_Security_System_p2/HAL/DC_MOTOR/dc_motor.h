/************************************************************************************
 * Module		: DC Motor Driver
 * File Name	: dc_motor.h
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: Header file for the DC Motor Driver
 ************************************************************************************/
#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

#include "../../MCAL/GPIO/gpio.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/PWM/pwm.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_INPUT_PORT_ID		PORTD_ID	/* Configurable motor control port */
#define DC_MOTOR_ENABLE_PORT_ID		PORTB_ID	/* Configurable motor control port */
#define DC_MOTOR_PIN1_ID			PIN7_ID		/* Control pin for direction */
#define DC_MOTOR_PIN2_ID			PIN6_ID		/* Control pin for direction */
#define DC_MOTOR_ENABLE_PIN_ID		PIN3_ID		/* Enable pin for PWM */

typedef enum {
	DC_MOTOR_CW,	/* Clockwise */
	DC_MOTOR_ACW,	/* Anti-Clockwise */
	DC_MOTOR_STOP	/* Stop */
} DC_Motor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * 	- Initializes the DC motor by setting the direction for the motor pins.
 * 	- Stops the motor at the beginning.
 */
void DC_Motor_Init(void);

/*
 * Description :
 * 	- Controls the motor's state (CW, A-CW, Stop) and adjusts the speed.
 * 	- state: The motor direction (CW, A-CW, Stop).
 * 	- speed: Motor speed in percentage (0 to 100%).
 */
void DC_Motor_Rotate(DC_Motor_State state, uint8 speed);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
