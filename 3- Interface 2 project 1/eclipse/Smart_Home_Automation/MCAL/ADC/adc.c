/************************************************************************************
 * File Name	: adc.c
 * Author		: Mahmoud 3smat
 * Created on	: 5/10/2024
 * Description	: ADC Driver
 ***********************************************************************************/
#include "adc.h"

/******************************************************************************
 *                      Functions Definitions                                  *
 ******************************************************************************/
void ADC_init(void)
{
	/******************** Selecting voltage Reference **********************/
	ADMUX_REG &= ADC_VOLTAGE_REF_CLR_MSK;
	ADMUX_REG |= ADC_VOLTAGE_REF_SELECTOR_MSK;
	/***********************************************************************/

	/************************ Selecting ADC Mode ***************************/
#if (ADC_MODE_SELECTOR == ADC_MODE_AUTO_TRIGGER)
	SET_BIT(ADCSRA_REG, ADC_AUTO_TRIGGER_ENABLE);
	SFIOR_REG &= ADC_AUTO_TRIG_SRC_CLR_MSK;
	SFIOR_REG |= ADC_AUTO_TRIG_SRCE_SELECTOR;

#elif (ADC_MODE_SELECTOR == ADC_MODE_SINGLE_CONVERSION)
	CLEAR_BIT(ADCSRA_REG, ADC_AUTO_TRIGGER_ENABLE);

#endif
	/***********************************************************************/

	/*********************** Selecting Adjustment **************************/
#if (ADC_ADJUSTMENT_SELECTOR == ADC_RIGHT_ADJUSTED)
	CLEAR_BIT(ADMUX_REG, ADC_LEFT_ADJUST_RESULT);

#elif ((ADC_ADJUSTMENT_SELECTOR == ADC_LEFT_ADJUSTED))
	SET_BIT(ADMUX_REG, ADC_LEFT_ADJUST_RESULT);

#endif
	/***********************************************************************/

	/**************************** Enabling ADC *****************************/
	SET_BIT(ADCSRA_REG, ADC_ENABLE);
	/***********************************************************************/
}

uint16 ADC_readChannel(ADC_channel_types ADC_channel)
{
	/********************** Selecting ADC Channel **************************/
	/*
	 * ADC_channel &= 0x07;
	 * ADMUX &= 0xE0;
	 * ADMUX = ADMUX | ADC_channel;
	 */
	ADMUX_REG = (ADMUX_REG & ADC_CHANNEL_SELECTOR_CLR_MSK) | (ADC_channel & ADC_channel7);
	/***********************************************************************/

	/************************* Start Conversion ****************************/
	SET_BIT(ADCSRA_REG, ADC_START_CONVERSION);
	/***********************************************************************/

	/**************************** Get Result *******************************/
	/* Wait for conversion to complete, ADIF becomes '1' */
	while(BIT_IS_CLEAR(ADCSRA_REG, ADC_INTERRUPT_FLAG));
	/***********************************************************************/

	/********************** Clearing Interrupt Flag ************************/
	SET_BIT(ADCSRA_REG, ADC_INTERRUPT_FLAG);	 /* Clear by 1 not 0 */
	/***********************************************************************/

	return ADC_REG;	 /* Read the digital value from the data register */
	/***********************************************************************/
}

