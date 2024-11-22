/************************************************************************************
 * Module		: PWM
 * File Name	: pwm.c
 * Author		: Mahmoud 3smat
 * Created on	: 26/10/2024
 * Description	: Source file for the PWM AVR driver
 ************************************************************************************/
#include "pwm.h"

void PWM_Timer0_Start(uint8_t duty_cycle)
{
    /* Set OC0 (PB3) as output */
    DDRB |= (1 << PB3);

    /* Set Fast PWM mode, non-inverting */
    TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01) | (1 << CS00); // Prescaler F_CPU/64

    /* Set the duty cycle */
    /* 0% -> 0, 100% -> 255 */
    if (duty_cycle <= 100) {
        OCR0 = (duty_cycle * 255) / 100;
    } else {
        OCR0 = 255; /* Maximum duty cycle if value exceeds 100% */
    }
}
