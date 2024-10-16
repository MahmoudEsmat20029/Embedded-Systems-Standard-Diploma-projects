/************************************************************************************
 * Module		: ADC
 * File Name	: adc_config.h
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: ADC Configuration
 ************************************************************************************/
#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

/*
 * Configure the voltage reference Range:
 * 		- ADC_VOLTAGE_REF_AVCC
 * 		- ADC_VOLTAGE_REF_AREF
 * 		- ADC_VOLTAGE_REF_2_56v
 */
#define ADC_VOLTAGE_REF_SELECTOR_MSK	ADC_VOLTAGE_REF_2_56v
#define ADC_REF_VOLT_VALUE				2.56
#define ADC_MAX_NUMBER_OF_STEPS			1024
/****************************************************************************/

/*
 * Configure the ADC mode Range:
 * 		- ADC_MODE_AUTO_TRIGGER
 *		- ADC_MODE_SINGLE_CONVERSION
 */
#define ADC_MODE_SELECTOR				ADC_MODE_SINGLE_CONVERSION
/****************************************************************************/

/*
 * Configure the ADC mode Range:
 * 		- ADC_RIGHT_ADJUSTED
 * 		- ADC_LEFT_ADJUSTED
 */
#define ADC_ADJUSTMENT_SELECTOR			ADC_RIGHT_ADJUSTED
/****************************************************************************/

/*
 * Configure the ADC prescalar Range:
 * 		- ADC_PRESCALER_2_MSK
 * 		- ADC_PRESCALER_4_MSK
 * 		- ADC_PRESCALER_8_MSK
 * 		- ADC_PRESCALER_16_MSK
 * 		- ADC_PRESCALER_32_MSK
 * 		- ADC_PRESCALER_64_MSK
 * 		- ADC_PRESCALER_128_MSK
 */
#define ADC_PRESCALAR_SELECTOR_msk		ADC_PRESCALER_128_MSK
/****************************************************************************/

/*
 * Configure the ADC trigger source Range:
 * 		- ADC_AUTO_TRIG_SRC_FREE_RUNINNG_MSK
 *		- ADC_AUTO_TRIG_SRC_ANALOG_COMP_MSK
 *		- ADC_AUTO_TRIG_SRC_EXTI0_MSK
 *		- ADC_AUTO_TRIG_SRC_TIMER0_COMP_MSK
 *		- ADC_AUTO_TRIG_SRC_TIMER0_OVF_MSK
 * 		- ADC_AUTO_TRIG_SRC_TIMER1_COMP_MSK
 * 		- ADC_AUTO_TRIG_SRC_TIMER1_OVF_MSK
 *		- ADC_AUTO_TRIG_SRC_TIMER0_CAPT_MSK
 */
#define ADC_AUTO_TRIG_SRCE_SELECTOR		ADC_AUTO_TRIG_SRC_FREE_RUNINNG_MSK
/****************************************************************************/

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
