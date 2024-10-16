/************************************************************************************
 * Module		: PWM
 * File Name	: pwm_registers.h
 * Author		: Mahmoud 3smat
 * Created on	: 25/9/2024
 * Description	: Definition of registers
 ************************************************************************************/
#ifndef MCAL_PWM_PWM_REGISTERS_H_
#define MCAL_PWM_PWM_REGISTERS_H_

#include "../../LIB/std_types.h"

/********************** TIMER 0 Registers Definitions *************************/
#define TCCR0_REG   *((volatile uint8*) 0x53)  /* Timer/Counter Control Register 0 */
#define TCNT0_REG   *((volatile uint8*) 0x52)  /* Timer/Counter Register 0 */
#define OCR0_REG    *((volatile uint8*) 0x5C)  /* Output Compare Register 0 */
#define TIMSK_REG   *((volatile uint8*) 0x59)  /* Timer/Counter Interrupt Mask Register */
/*******************************************************************************/

#endif /* MCAL_PWM_PWM_REGISTERS_H_ */
