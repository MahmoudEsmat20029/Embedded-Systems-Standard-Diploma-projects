/************************************************************************************
 * Module		: Common - Platform Types Abstraction
 * File Name	: adc_types.h
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: types for AVR
 ************************************************************************************/
#ifndef MCAL_ADC_ADC_TYPES_H_
#define MCAL_ADC_ADC_TYPES_H_

#include "../../MCAL/GPIO/gpio_types.h"

/* ADC SET and CLEAR */
#define ADC_AUTO_TRIGGER_ENABLE			PIN5_ID		/* ADCSRA_REG */
#define ADC_LEFT_ADJUST_RESULT			PIN5_ID		/* ADMUX_REG */
#define ADC_INTERRUPT_FLAG				PIN4_ID		/* ADCSRA_REG */
#define ADC_ENABLE						PIN7_ID		/* ADCSRA_REG */
#define ADC_START_CONVERSION			PIN6_ID		/* ADCSRA_REG */

/* ADC Voltage select */
#define ADC_VOLTAGE_REF_CLR_MSK			0x3F
#define ADC_VOLTAGE_REF_AVCC			0x40
#define ADC_VOLTAGE_REF_AREF			0x00
#define ADC_VOLTAGE_REF_2_56v			0xC0

/* ADC mode select */
#define ADC_MODE_AUTO_TRIGGER			1
#define ADC_MODE_SINGLE_CONVERSION		0

/* ADC adjust select */
#define ADC_RIGHT_ADJUSTED				0
#define ADC_LEFT_ADJUSTED				1

/* ADC prescalar select */
#define ADC_PRESCALER_CLR_MASK			0xF8
#define ADC_PRESCALER_2_MSK				0x00
#define ADC_PRESCALER_4_MSK				0x02
#define ADC_PRESCALER_8_MSK				0x03
#define ADC_PRESCALER_16_MSK			0x04
#define ADC_PRESCALER_32_MSK			0x05
#define ADC_PRESCALER_64_MSK			0x06
#define ADC_PRESCALER_128_MSK			0x07

/* ADC auto trigger select */
#define ADC_AUTO_TRIG_SRC_CLR_MSK				0x1F
#define ADC_AUTO_TRIG_SRC_FREE_RUNINNG_MSK		0x00
#define ADC_AUTO_TRIG_SRC_ANALOG_COMP_MSK		0x20
#define ADC_AUTO_TRIG_SRC_EXTI0_MSK				0x40
#define ADC_AUTO_TRIG_SRC_TIMER0_COMP_MSK		0x60
#define ADC_AUTO_TRIG_SRC_TIMER0_OVF_MSK		0x80
#define ADC_AUTO_TRIG_SRC_TIMER1_COMP_MSK		0xA0
#define ADC_AUTO_TRIG_SRC_TIMER1_OVF_MSK		0xC0
#define ADC_AUTO_TRIG_SRC_TIMER0_CAPT_MSK		0xE0

/* ADC mask to clear channel */
#define ADC_CHANNEL_SELECTOR_CLR_MSK	0xE0

#endif /* MCAL_ADC_ADC_TYPES_H_ */
