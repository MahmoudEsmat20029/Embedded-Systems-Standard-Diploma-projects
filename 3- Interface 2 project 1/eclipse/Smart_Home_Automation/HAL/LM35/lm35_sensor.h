/************************************************************************************
 * Module		: Temperature Sensor
 * File Name	: lm35_sensor.h
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: header file for the LM35 Temperature Sensor driver
 ************************************************************************************/
#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "../../LIB/std_types.h"
#include "../../MCAL/ADC/adc.h"
#include "../../MCAL/GPIO/gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LM35_SENSOR_CHANNEL_ID			1
#define LM35_SENSOR_MAX_VOLT_VALUE		1.5
#define LM35_SENSOR_MAX_TEMPERATURE		150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * 		- Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
