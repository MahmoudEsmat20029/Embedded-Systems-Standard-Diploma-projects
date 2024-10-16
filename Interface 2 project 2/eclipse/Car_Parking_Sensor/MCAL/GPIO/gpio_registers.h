/************************************************************************************
 * Module		: GOIO
 * File Name	: gpio_registers.h
 * Author		: Mahmoud 3smat
 * Created on	: 25/9/2024
 * Description	: Definition of registers
 ************************************************************************************/
#ifndef MCAL_GPIO_GPIO_REGISTERS_H_
#define MCAL_GPIO_GPIO_REGISTERS_H_

/*********************************** GPIO Registers Definitions ********************************/
#define PORTA_REG 	*((volatile uint8*) 0x3B)		/* Definition register of PORTA */
#define DDRA_REG 	*((volatile uint8*) 0x3A)		/* Definition register of DDRA */
#define PINA_REG 	*((volatile uint8*) 0x39)		/* Definition register of PINA */

#define PORTB_REG	*((volatile uint8*) 0x38)		/* Definition register of PORTB */
#define DDRB_REG 	*((volatile uint8*) 0x37)		/* Definition register of DDRB */
#define PINB_REG 	*((volatile uint8*) 0x36)		/* Definition register of PINB */

#define PORTC_REG 	*((volatile uint8*) 0x35)		/* Definition register of PORTC */
#define DDRC_REG 	*((volatile uint8*) 0x34)		/* Definition register of DDRC */
#define PINC_REG 	*((volatile uint8*) 0x33)		/* Definition register of PINC */

#define PORTD_REG 	*((volatile uint8*) 0x32)		/* Definition register of PORTD */
#define DDRD_REG 	*((volatile uint8*) 0x31)		/* Definition register of DDRD */
#define PIND_REG 	*((volatile uint8*) 0x30)		/* Definition register of PIND */
/***********************************************************************************************/

#endif /* MCAL_GPIO_GPIO_REGISTERS_H_ */
