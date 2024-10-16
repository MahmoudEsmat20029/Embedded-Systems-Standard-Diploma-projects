/************************************************************************************
 * Module		: GOIO
 * File Name	: gpio.h
 * Author		: Mahmoud 3smat
 * Created on	: 25/9/2024
 * Description	: Source file for the AVR GPIO driver
 ************************************************************************************/
#ifndef MCAL_GPIO_GPIO_H_
#define MCAL_GPIO_GPIO_H_

#include "gpio_types.h"
#include "gpio_registers.h"
#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"

/*******************************************************************************
 *                           Functions Prototypes                              *
 *******************************************************************************/
/*
 * Description :
 * 		- Setup the direction of the required pin input/output.
 * 		- If the input port number or pin number are not correct, The function will do nothing.
 */
void GPIO_setupPinDirection(GPIO_PORT_ID port_id, GPIO_PIN_ID pin_id, GPIO_PinDirection direction);

/*
 * Description :
 * 	for output pin:
 * 		- Write the value Logic High or Logic Low on the required pin.
 * 		- If the input port number or pin number are not correct, The function will do nothing.
 * 	for input pin:
 * 		- This function will enable/disable the 'internal pull-up' resistor.
 */
void GPIO_writePin(GPIO_PORT_ID port_id, GPIO_PIN_ID pin_id, STD_Value value);

/*
 * Description :
 * 		- Read and return the value for the required pin, it should be Logic High or Logic Low.
 * 		- If the input port number or pin number are not correct, The function will return Logic Low.
 */
STD_Value GPIO_readPin(GPIO_PORT_ID port_id, GPIO_PIN_ID pin_id);

/*
 * Description :
 * 		- Setup the direction of the required port all pins input/output.
 * 		- If the input port number is not correct, The function will do nothing.
 * 		- If the direction value is PORT_INPUT all pins in this port should be input pins.
 * 		- If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 */
void GPIO_setupPortDirection(GPIO_PORT_ID port_id, GPIO_PortDirection direction);

/*
 * Description :
 * 		- Write the value on the required port.
 * 		- If any pin in the port is output pin the value will be written.
 * 		- If any pin in the port is input pin this will activate/deactivate the 'internal pull-up' resistor.
 * 		- If the input port number is not correct, The function will do nothing.
 */
void GPIO_writePort(GPIO_PORT_ID port_id, uint8 value);

#endif /* MCAL_GPIO_GPIO_H_ */
