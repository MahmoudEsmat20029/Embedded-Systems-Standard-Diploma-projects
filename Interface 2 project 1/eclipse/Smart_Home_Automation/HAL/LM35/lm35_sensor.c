/************************************************************************************
 * Module		: Temperature Sensor
 * File Name	: lm35_sensor.c
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: source file for the LM35 Temperature Sensor driver
 ************************************************************************************/
#include "lm35_sensor.h"

uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	ADC_init();

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(LM35_SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value * LM35_SENSOR_MAX_TEMPERATURE * ADC_REF_VOLT_VALUE) / (ADC_MAX_NUMBER_OF_STEPS * LM35_SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

