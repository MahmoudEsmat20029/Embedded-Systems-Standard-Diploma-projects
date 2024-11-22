/************************************************************************************
 * Module		: LED Driver
 * File Name	: led.h
 * Author		: Mahmoud 3smat
 * Created on	: 6/10/2024
 * Description	: Header file for the LED Driver
 ************************************************************************************/
#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include "../../LIB/std_types.h"
#include "../../MCAL/GPIO/gpio.h"
#include "../../LIB/common_macros.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LED_RED_PORT_ID   	PORTC_ID
#define LED_RED_PIN_ID    	PIN0_ID

#define LED_GREEN_PORT_ID 	PORTC_ID
#define LED_GREEN_PIN_ID  	PIN1_ID

#define LED_BLUE_PORT_ID  	PORTC_ID
#define LED_BLUE_PIN_ID   	PIN2_ID

typedef enum
{
    LED_RED,
    LED_GREEN,
    LED_BLUE
} LED_ID;

/* LED Logic Types */
typedef enum
{
    POSITIVE_LOGIC,
    NEGATIVE_LOGIC
} LED_Logic;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * 	- Initializes all LEDs (red, green, blue) pins direction.
 * 	- Turns off all the LEDs.
 */
void LEDS_init(void);

/*
 * Description :
 * 	- Turns on the specified LED.
 * 	- id: The LED ID (RED, GREEN, BLUE).
 */
void LED_on(LED_ID id);

/*
 * Description :
 * 	- Turns off the specified LED.
 * 	- id: The LED ID (RED, GREEN, BLUE).
 */
void LED_off(LED_ID id);

/*
 * Description:
 * 	- Set the LED logic type (Positive or Negative)
 */
 void LED_setLogic(LED_Logic logic);

#endif /* HAL_LED_LED_H_ */
