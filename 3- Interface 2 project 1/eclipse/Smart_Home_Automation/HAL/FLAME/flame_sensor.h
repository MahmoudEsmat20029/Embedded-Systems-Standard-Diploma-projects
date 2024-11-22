/************************************************************************************
 * Module		: Flame Sensor
 * File Name	: flame_sensor.h
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: header file for the Flame Sensor driver
 ************************************************************************************/
#ifndef HAL_FLAME_FLAME_SENSOR_H_
#define HAL_FLAME_FLAME_SENSOR_H_

#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define FLAME_SENSOR_PORT_ID   PORTD_ID
#define FLAME_SENSOR_PIN_ID    PIN2_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * 		- Function to initialize the flame sensor pin as input.
 */
void FlameSensor_init(void);
/*
 * Description :
 * 		- Function responsible for reading the flame sensor value.
 * 		- Returns 1 if fire is detected, 0 otherwise.
 */
uint8 FlameSensor_getValue(void);

#endif /* HAL_FLAME_FLAMESENSOR_H_ */
