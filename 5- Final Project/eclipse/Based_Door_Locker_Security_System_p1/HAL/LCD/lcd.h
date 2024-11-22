/************************************************************************************
 * Module		: LCD
 * File Name	: lcd.h
 * Author		: Mahmoud 3smat
 * Created on	: 1/10/2024
 * Description	: Source file for the AVR LCD driver
 ************************************************************************************/
#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"
#include "../../MCAL/GPIO/gpio.h"
#include <avr/delay.h>

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
/* LCD Data bits mode configuration, its value should be 4 or 8*/
#define LCD_DATA_BITS_MODE 8

#if((LCD_DATA_BITS_MODE != 4) && (LCD_DATA_BITS_MODE != 8))

#error "Number of Data bits should be equal to 4 or 8"

#endif

/* LCD HW Ports and Pins Ids */
#define LCD_RS_PORT_ID		PORTC_ID
#define LCD_RS_PIN_ID		PIN0_ID

#define LCD_EN_PORT_ID		PORTC_ID
#define LCD_EN_PIN_ID		PIN1_ID

#define LCD_DATA_PORT_ID	PORTA_ID

#if (LCD_DATA_BITS_MODE == 4)

#define LCD_DB4_PIN_ID		PIN3_ID
#define LCD_DB5_PIN_ID		PIN4_ID
#define LCD_DB6_PIN_ID		PIN5_ID
#define LCD_DB7_PIN_ID		PIN6_ID

#endif

/* LCD Commands */
#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * 	- Initialize the LCD:
 * 		1. Setup the LCD pins directions by use the GPIO driver.
 * 		2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * 		- Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * 		- Display the required character on the screen
 */
void LCD_displayCharacter(uint8 data);

/*
 * Description :
 * 		- Display the required string on the screen
 */
void LCD_displayString(const char *Str);

/*
 * Description :
 * 		- Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col);

/*
 * Description :
 * 		- Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str);

/*
 * Description :
 * 		- Display the required decimal value on the screen
 */
void LCD_intgerToString(int data);

/*
 * Description :
 * 		- Send the clear screen command
 */
void LCD_clearScreen(void);

#endif /* HAL_LCD_LCD_H_ */
