/************************************************************************************
 * Module		: Smart Home Automation
 * File Name	: Smart_Home_Automation.h
 * Author		: Mahmoud 3smat
 * Created on	: 7/10/2024
 * Description	: Main application file for the smart home automation system
 ************************************************************************************/
#ifndef SMART_HOME_AUTOMATIO_H_
#define SMART_HOME_AUTOMATIO_H_

/*************** MCAL Drivers ******************/
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/ADC/adc.h"
#include "../MCAL/PWM/pwm.h"

/*************** LIB Drivers ******************/
#include "../LIB/common_macros.h"
#include "../LIB/std_types.h"

/*************** HAL Drivers ******************/
#include "../HAL/FLAME/flame_sensor.h"
#include "../HAL/DC_MOTOR/dc_motor.h"
#include "../HAL/LM35/lm35_sensor.h"
#include "../HAL/LDR/ldr_sensor.h"
#include "../HAL/BUZZER/buzzer.h"
#include "../HAL/LED/led.h"
#include "../HAL/LCD/lcd.h"

/*************** Application ******************/
#include <util/delay.h>

#endif /* SMART_HOME_AUTOMATIO_H_ */
