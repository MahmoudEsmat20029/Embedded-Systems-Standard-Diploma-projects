/************************************************************************************
 * Module		: PWM
 * File Name	: pwm.h
 * Author		: Mahmoud 3smat
 * Created on	: 26/10/2024
 * Description	: Header file for the PWM AVR driver
 ************************************************************************************/
#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../../LIB/std_types.h"
#include "../GPIO/gpio.h"
#include <avr/io.h>

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * 		- Functional responsible for initializing Timer0 in PWM mode and setting the duty cycle.
 * Parameters:
 * 		- duty_cycle: Percentage (0 to 100%) representing the PWM duty cycle.
 */
void PWM_Timer0_Start(uint8_t duty_cycle);

#endif /* MCAL_PWM_PWM_H_ */
