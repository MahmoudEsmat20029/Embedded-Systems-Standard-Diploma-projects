/************************************************************************************
 * Module		: Common - Platform Types Abstraction
 * File Name	: pwm_types.h
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: types for AVR
 ************************************************************************************/
#ifndef MCAL_PWM_PWM_TYPES_H_
#define MCAL_PWM_PWM_TYPES_H_

#include "../GPIO/gpio_types.h"

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define PWM_TIMER0_WGM00		PIN6_ID		/* TCCR0_REG */
#define PWM_TIMER0_WGM01   		PIN3_ID		/* TCCR0_REG */
#define PWM_TIMER0_COM01   		PIN5_ID		/* TCCR0_REG */
#define PWM_TIMER0_CS00    		PIN0_ID		/* TCCR0_REG */
#define PWM_TIMER0_CS01    		PIN1_ID		/* TCCR0_REG */

/* PWM Mode */
#define PWM_FAST				1
#define PWM_PHASE_CORRECT		2
#define PWM_NON_INVERTING		3
#define PWM_INVERTING			4

/* PWM Prescaler Masks */
#define PWM_PRESCALER_CLR_MASK     0xF8
#define PWM_PRESCALER_1_MSK        0x01
#define PWM_PRESCALER_8_MSK        0x02
#define PWM_PRESCALER_64_MSK       0x03
#define PWM_PRESCALER_256_MSK      0x04
#define PWM_PRESCALER_1024_MSK     0x05

#endif /* MCAL_PWM_PWM_TYPES_H_ */
