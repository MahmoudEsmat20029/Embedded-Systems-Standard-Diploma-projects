/************************************************************************************
 * Module      : Ultrasonic Driver
 * File Name   : ultrasonic.c
 * Author      : Mahmoud 3smat
 * Created on  : 8/10/2024
 * Description : Source file for the Ultrasonic Driver
 ************************************************************************************/
#include "ultrasonic.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Variable to store the pulse duration */
static volatile uint16 highTime = 0;

/*******************************************************************************
 *                           Functions Definitions                              *
 *******************************************************************************/
void Ultrasonic_init(void) {
    /* Initialize the ICU driver with required configurations */
    ICU_ConfigType icuConfig;
    icuConfig.clock = F_CPU_8; /* Set edge type */
    icuConfig.edge = RAISING; /* Set clock source */
    ICU_init(&icuConfig); /* Call the ICU_init function */

    /* Set the trigger pin as output */
    GPIO_setupPinDirection(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, PIN_OUTPUT);

    /* Set the echo pin as input */
    GPIO_setupPinDirection(ULTRASONIC_ECHO_PORT_ID, ULTRASONIC_ECHO_PIN_ID, PIN_INPUT);

    /* Set the callback function for edge detection */
    ICU_setCallBack(Ultrasonic_edgeProcessing);
}

void Ultrasonic_Trigger(void) {
    /* Send a 10 µs high pulse to the ultrasonic sensor */
    GPIO_writePin(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, LOGIC_HIGH);
    _delay_us(10); /* Trigger pulse duration */
    GPIO_writePin(ULTRASONIC_TRIG_PORT_ID, ULTRASONIC_TRIG_PIN_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void) {
    /* Send the trigger pulse */
    Ultrasonic_Trigger();

    /* Start the measurement process via the ICU driver */
    return (highTime / 58); /* Convert to centimeters */
}

void Ultrasonic_edgeProcessing(void) {
    static uint8 edgeCount = 0; /* Counter for edges detected */

    edgeCount++;

    if (1 == edgeCount)
    {
        /* Rising edge detected, start timing */
        highTime = 0; /* Reset the high time */
        ICU_setEdgeDetectionType(FALLING); /* Change to falling edge detection */
        ICU_clearTimerValue(); /* Clear timer value for the next measurement */
    }
    else if (2 == edgeCount)
    {
        /* Falling edge detected, stop timing */
        highTime = ICU_getInputCaptureValue(); /* Get the high time */
        ICU_setEdgeDetectionType(RAISING); /* Change to rising edge detection for next measurement */
        edgeCount = 0; /* Reset edge count */
    }
}

