/************************************************************************************
 * Module		: Common - Platform Types Abstraction
 * File Name	: gpio_types.h
 * Author		: Mahmoud 3smat
 * Created on	: 25/9/2024
 * Description	: types for AVR
 ************************************************************************************/
#ifndef MCAL_GPIO_GPIO_TYPES_H_
#define MCAL_GPIO_GPIO_TYPES_H_

/*******************************************************************************
 *                              Definitions                                    *
 *******************************************************************************/
#define NUM_OF_PORTS           4	/* ports A, B, C and D */
#define NUM_OF_PINS_PER_PORT   8	/* pins [0 --> 7] */
/*******************************************************************************
 *                           Types Declaration                                 *
 *******************************************************************************/
typedef enum
{
	PIN_INPUT,		/* 0 */
	PIN_OUTPUT		/* 1 */
}GPIO_PinDirection;

typedef enum
{
	PORT_INPUT,				/* 0000 0000 */
	PORT_OUTPUT = 0xFF		/* 1111 1111 */
}GPIO_PortDirection;

typedef enum
{
	PORTA_ID,	/* port number A */
	PORTB_ID,	/* port number B */
	PORTC_ID,	/* port number C */
	PORTD_ID	/* port number D */
}GPIO_PORT_ID;

typedef enum
{
	PIN0_ID,	/* pin number 0 */
	PIN1_ID,	/* pin number 1 */
	PIN2_ID,	/* pin number 2 */
	PIN3_ID,	/* pin number 3 */
	PIN4_ID,	/* pin number 4 */
	PIN5_ID,	/* pin number 5 */
	PIN6_ID,	/* pin number 6 */
	PIN7_ID,	/* pin number 7 */
}GPIO_PIN_ID;

#endif /* MCAL_GPIO_GPIO_TYPES_H_ */
