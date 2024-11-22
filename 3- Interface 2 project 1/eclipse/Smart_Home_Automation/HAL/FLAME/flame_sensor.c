/************************************************************************************
 * Module		: Flame Sensor
 * File Name	: flame_sensor.c
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: source file for the Flame Sensor driver
 ************************************************************************************/
#include "flame_sensor.h"

void FlameSensor_init(void)
{
    /* Configure the flame sensor pin as input */
    GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID, PIN_INPUT);
}

uint8 FlameSensor_getValue(void)
{
    /* Read the value from the flame sensor pin */
    return GPIO_readPin(FLAME_SENSOR_PORT_ID, FLAME_SENSOR_PIN_ID);
}
