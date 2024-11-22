/************************************************************************************
 * Module		: Car Parking Sensor
 * File Name	: Car_Parking_Sensor.h
 * Author		: Mahmoud 3smat
 * Created on	: 8/10/2024
 * Description	: Main application file for the Car Parking Sensor
 ************************************************************************************/
#ifndef APP_CAR_PARKING_SENSOR_H_
#define APP_CAR_PARKING_SENSOR_H_

/*************** MCAL Drivers ******************/
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/ICU/icu.h"

/*************** LIB Drivers ******************/
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"

/*************** HAL Drivers ******************/
#include "../HAL/Ultrasonic/ultrasonic.h"
#include "../HAL/BUZZER/buzzer.h"
#include "../HAL/LED/led.h"
#include "../HAL/LCD/lcd.h"

/*************** Application ******************/
#include <util/delay.h>

#endif /* APP_CAR_PARKING_SENSOR_H_ */
