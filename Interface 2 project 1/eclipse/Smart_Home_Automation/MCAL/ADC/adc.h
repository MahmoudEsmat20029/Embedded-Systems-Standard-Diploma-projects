/***********************************************************************************
 * Module		: ADC
 * File Name	: adc.h
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: Source file for the AVR ADC driver
 ***********************************************************************************/
#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include "adc_registers.h"
#include "adc_config.h"
#include "adc_types.h"

/******************************************************************************
 *                           Types Declaration                                 *
 ******************************************************************************/
typedef enum
{
	ADC_channel0,
	ADC_channel1,
	ADC_channel2,
	ADC_channel3,
	ADC_channel4,
	ADC_channel5,
	ADC_channel6,
	ADC_channel7
}ADC_channel_types;

/******************************************************************************
 *                           Functions Prototypes                              *
 ******************************************************************************/

/* Description :
 * 		- Function responsible for initialize the ADC driver.
 */
void ADC_init(void);


/* Description :
 * 		- Function responsible for read analog data from a certain ADC channel
 * 		  and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(ADC_channel_types ADC_channel);

#endif  MCAL_ADC_ADC_H_



