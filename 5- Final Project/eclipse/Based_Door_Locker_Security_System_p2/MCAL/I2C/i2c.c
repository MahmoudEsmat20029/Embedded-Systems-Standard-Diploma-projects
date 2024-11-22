/******************************************************************************
 * Module: I2C(TWI)
 * File Name: i2c.c
 * Author: Mahmoud 3smat
 * Description: Source file for the I2C(TWI) AVR driver
 *******************************************************************************/
#include "i2c.h"

void TWI_init(const TWI_ConfigType * Config_Ptr)
{
	// Set the TWI Bit Rate based on the configuration structure
	TWBR = Config_Ptr->bit_rate;  // Bit Rate: Set based on configuration
	TWSR = 0x00;                   // Prescaler value (0)

	// Set the Two Wire Bus address based on the configuration structure
	TWAR = Config_Ptr->address;    // Set TWI address from configuration

	TWCR = (1 << TWEN);            // Enable TWI
}

void TWI_start(void)
{
	// Clear the TWINT flag before sending the start bit
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

	// Wait for TWINT flag set in TWCR Register (start bit is sent successfully)
	while (BIT_IS_CLEAR(TWCR, TWINT));
}

void TWI_stop(void)
{
	// Clear the TWINT flag before sending the stop bit
	TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_writeByte(uint8_t data)
{
	// Put data on TWI data Register
	TWDR = data;

	// Clear the TWINT flag before sending the data
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for TWINT flag set in TWCR Register (data is sent successfully)
	while (BIT_IS_CLEAR(TWCR, TWINT));
}

uint8_t TWI_readByteWithACK(void)
{
	// Clear the TWINT flag before reading the data and enable ACK
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);

	// Wait for TWINT flag set in TWCR Register (data received successfully)
	while (BIT_IS_CLEAR(TWCR, TWINT));

	// Read Data
	return TWDR;
}

uint8_t TWI_readByteWithNACK(void)
{
	// Clear the TWINT flag before reading the data
	TWCR = (1 << TWINT) | (1 << TWEN);

	// Wait for TWINT flag set in TWCR Register (data received successfully)
	while (BIT_IS_CLEAR(TWCR, TWINT));

	// Read Data
	return TWDR;
}

uint8_t TWI_getStatus(void)
{
	uint8_t status;

	// Masking to eliminate first 3 bits and get the last 5 bits (status bits)
	status = TWSR & 0xF8;
	return status;
}
