/************************************************************************************
 * Module		: LDR Sensor
 * File Name	: ldr_sensor.h
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: header file for the LDR sensor driver
 ************************************************************************************/
#ifndef HAL_LDR_LDR_SENSOR_H_
#define HAL_LDR_LDR_SENSOR_H_

#include "../../MCAL/GPIO/gpio.h"
#include "../../LIB/std_types.h"
#include "../../MCAL/ADC/adc.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LDR_SENSOR_CHANNEL_ID         	0
#define LDR_SENSOR_MAX_VOLT_VALUE     	2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY	100

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description:
 * 	- Reads the LDR sensor value and returns the light intensity.
 * 	- The light intensity is expressed as a percentage (0% → 100%).
 */
uint8 LDR_getLightIntensity(void);

#endif /* HAL_LDR_LDR_SENSOR_H_ */
