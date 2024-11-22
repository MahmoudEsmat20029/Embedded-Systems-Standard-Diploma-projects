/************************************************************************************
 * Module		: LDR Sensor
 * File Name	: ldr_sensor.c
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: source file for the LDR Sensor driver
 ************************************************************************************/
#include "ldr_sensor.h"

uint8 LDR_getLightIntensity(void)
{
	uint8 lightIntensity = 0;

	uint16 adc_value = 0;

	ADC_init();

	/* Read ADC channel where the LDR sensor is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the light from the ADC value*/
	lightIntensity = (uint8)(((uint32)adc_value * LDR_SENSOR_MAX_LIGHT_INTENSITY * ADC_REF_VOLT_VALUE) / (ADC_MAX_NUMBER_OF_STEPS * LDR_SENSOR_MAX_VOLT_VALUE));

	return lightIntensity;
}
