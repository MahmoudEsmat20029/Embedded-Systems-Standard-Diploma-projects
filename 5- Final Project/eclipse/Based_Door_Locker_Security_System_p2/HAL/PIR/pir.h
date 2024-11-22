/******************************************************************************
 * Module		: PIR Sensor Driver
 * File Name	: pir.h
 * Author		: Mahmoud 3smat
 * Created on	: 27/10/2024
 * Description	: Header file for the PIR Sensor driver
 *******************************************************************************/
#ifndef HAL_PIR_PIR_H_
#define HAL_PIR_PIR_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include <avr/io.h>

#define PIR_PIN 	PIN2  // Change this to the actual pin connected to the PIR sensor

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void PIR_init(void);

uint8 PIR_getState(void);

#endif /* HAL_PIR_PIR_H_ */
