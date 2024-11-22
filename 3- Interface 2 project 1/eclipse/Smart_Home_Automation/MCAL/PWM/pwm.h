/***********************************************************************************
 * Module		: PWM
 * File Name	: pwm.h
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: Source file for the AVR PWM driver
 ***********************************************************************************/
#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include "pwm_registers.h"
#include "../GPIO/gpio.h"
#include "pwm_config.h"
#include "pwm_types.h"

/*******************************************************************************
 *                           Functions Prototypes                              *
 *******************************************************************************/
/*
 * Description:
 * 	- Initializes Timer0 in PWM mode.
 * 	- dutyCycle The duty cycle percentage (0-100).
 */
void PWM_Timer0_Init(uint8 dutyCycle);

/*
 * Description:
 * 	- Sets the duty cycle for Timer0 PWM.
 * 	- dutyCycle The duty cycle percentage (0-100).
 */
void PWM_Timer0_setDutyCycle(uint8 dutyCycle);

#endif /* MCAL_PWM_PWM_H_ */
