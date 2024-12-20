/************************************************************************************
 * Module		: KEYPAD
 * File Name	: keypad.h
 * Author		: Mahmoud 3smat
 * Created on	: 26/10/2024
 * Description	: Header file for the Keypad driver
 ************************************************************************************/
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/GPIO/gpio.h"
#include "../../LIB/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* Use Standard keypad type */
#define STANDARD_KEYPAD

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS					4
#define KEYPAD_NUM_ROWS					4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID				PORTB_ID
#define KEYPAD_FIRST_ROW_PIN_ID			PIN0_ID

#define KEYPAD_COL_PORT_ID				PORTB_ID
#define KEYPAD_FIRST_COL_PIN_ID			PIN4_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED			LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED			LOGIC_HIGH

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void);

#endif /* KEYPAD_H_ */
