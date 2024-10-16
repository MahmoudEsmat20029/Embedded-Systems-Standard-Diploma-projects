/************************************************************************************
 * File Name	: pwm.c
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: PWM Driver
 ***********************************************************************************/
#include "pwm.h"

void PWM_Timer0_Init(uint8 dutyCycle)
{
    SET_BIT(DDRB_REG, PIN3_ID);		/* Set OC0 pin as output */

    /* Configure PWM mode */
#if (PWM_MODE == PWM_FAST)
    {
    	SET_BIT(TCCR0_REG, PWM_TIMER0_WGM00);
    	SET_BIT(TCCR0_REG, PWM_TIMER0_WGM01);
    }
#elif (PWM_MODE == PWM_PHASE_CORRECT)
    {
    	SET_BIT(TCCR0_REG, PWM_TIMER0_WGM00);
    }
#elif (PWM_MODE == PWM_NON_INVERTING)
    {
    	SET_BIT(TCCR0_REG, PWM_TIMER0_WGM00);
    	SET_BIT(TCCR0_REG, PWM_TIMER0_WGM01);
    	SET_BIT(TCCR0_REG, PWM_TIMER0_COM01);  /* Set non-inverting mode */
    }
#elif (PWM_MODE == PWM_INVERTING)
    {
    	SET_BIT(TCCR0_REG, PWM_TIMER0_WGM00);
    	SET_BIT(TCCR0_REG, PWM_TIMER0_WGM01);
    	SET_BIT(TCCR0_REG, PWM_TIMER0_COM00);  /* Set inverting mode */
    }
#endif

    /* Clear the prescaler bits */
    TCCR0_REG &= PWM_PRESCALER_CLR_MASK;

    /* Set the prescaler value */
    TCCR0_REG |= PWM_PRESCALER;

    /* Set the duty cycle */
    PWM_Timer0_setDutyCycle(dutyCycle);
}

void PWM_Timer0_setDutyCycle(uint8 dutyCycle)
{
	/* Ensure duty cycle is between 0% and 100% */
    if (dutyCycle > 100)
    	dutyCycle = 100;

    /* Calculate and set the OCR0 value */
    OCR0_REG = (dutyCycle * 255) / 100;
}
