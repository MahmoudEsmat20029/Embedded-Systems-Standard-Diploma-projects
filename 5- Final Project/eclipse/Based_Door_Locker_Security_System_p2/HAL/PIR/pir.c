/******************************************************************************
 * Module		: PIR Sensor Driver
 * File Name	: pir.c
 * Author		: Mahmoud 3smat
 * Created on	: 27/10/2024
 * Description	: Source file for the PIR Sensor driver
 *******************************************************************************/
#include "pir.h"

void PIR_init(void)
{
    // Set the PIR_PIN as input
    DDRC &= ~(1 << PIR_PIN);  // Assuming the PIR is connected to PORTD
}

uint8 PIR_getState(void)
{
    // Read the state of the PIR sensor
    return (PINC & (1 << PIR_PIN)) ? 1 : 0;  // Return 1 if motion is detected, otherwise return 0
}
