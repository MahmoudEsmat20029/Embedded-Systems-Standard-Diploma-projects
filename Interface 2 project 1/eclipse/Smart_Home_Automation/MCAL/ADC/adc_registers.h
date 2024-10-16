/************************************************************************************
 * Module		: ADC
 * File Name	: adc_registers.h
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: Definition of registers
 ************************************************************************************/
#ifndef MCAL_ADC_ADC_REGISTERS_H_
#define MCAL_ADC_ADC_REGISTERS_H_

/*********************************** ADC Registers Definitions ********************************/
#define ADMUX_REG		*((volatile uint8 *) 0x27)		/* Definition register ADMUX  */
#define ADCSRA_REG		*((volatile uint8 *) 0x26)		/* Definition register ADCSRA */
#define SFIOR_REG		*((volatile uint8 *) 0x50)		/* Definition register SFIOR  */
#define ADCL_REG		*((volatile uint8 *) 0x24)		/* Definition register ADCL   */
#define ADCH_REG		*((volatile uint8 *) 0x25)		/* Definition register ADCH   */
#define ADC_REG			*((volatile uint16*) 0x24)		/* Definition register ADC    */
/***********************************************************************************************/

#endif /* MCAL_ADC_ADC_REGISTERS_H_ */
