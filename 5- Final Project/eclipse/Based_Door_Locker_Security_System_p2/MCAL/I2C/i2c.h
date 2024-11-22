/******************************************************************************
 * Module: I2C(TWI)
 * File Name: i2c.h
 * Author: Mahmoud 3smat
 * Description: Header file for the I2C(TWI) AVR driver
 *******************************************************************************/ 
#ifndef MCAL_I2C_TWI_H_
#define MCAL_I2C_TWI_H_

#include "../../LIB/common_macros.h"
#include "../../LIB/std_types.h"
#include <avr/io.h>

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
/* I2C Status Bits in the TWSR Register */
#define TWI_START         0x08 /* start has been sent */
#define TWI_REP_START     0x10 /* repeated start */
#define TWI_MT_SLA_W_ACK  0x18 /* Master transmit ( slave address + Write request ) to slave + ACK received from slave. */
#define TWI_MT_SLA_R_ACK  0x40 /* Master transmit ( slave address + Read request ) to slave + ACK received from slave. */
#define TWI_MT_DATA_ACK   0x28 /* Master transmit data and ACK has been received from Slave. */
#define TWI_MR_DATA_ACK   0x50 /* Master received data and send ACK to slave. */
#define TWI_MR_DATA_NACK  0x58 /* Master received data but doesn't send ACK to slave. */

/*******************************************************************************
 *                      Type Definitions                                        *
 *******************************************************************************/
typedef uint8_t TWI_AddressType;    // Example definition
typedef uint16_t TWI_BaudRateType;  // Example definition

typedef struct {
    TWI_AddressType address;       // TWI address
    TWI_BaudRateType bit_rate;     // TWI bit rate
} TWI_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void TWI_init(const TWI_ConfigType * Config_Ptr);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(uint8_t data);
uint8_t TWI_readByteWithACK(void);
uint8_t TWI_readByteWithNACK(void);
uint8_t TWI_getStatus(void);

#endif /* MCAL_I2C_TWI_H_ */
