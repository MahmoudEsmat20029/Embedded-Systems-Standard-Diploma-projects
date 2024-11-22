/************************************************************************************
 * Module		: UART
 * File Name	: uart_registers.h
 * Author		: Mahmoud 3smat
 * Created on	: 26/10/2024
 * Description	: Definition of registers
 ************************************************************************************/
#ifndef MCAL_UART_UART_REGISTERS_H_
#define MCAL_UART_UART_REGISTERS_H_

/*********************************** UART Registers Definitions ********************************/
#define UDR_REG       *((volatile uint8*) 0x2C)    /* USART Data Register */
#define UCSRA_REG     *((volatile uint8*) 0x2B)    /* USART Control and Status Register A */
#define UCSRB_REG     *((volatile uint8*) 0x2A)    /* USART Control and Status Register B */
#define UCSRC_REG     *((volatile uint8*) 0x40)    /* USART Control and Status Register C (requires URSEL bit) */
#define UBRRL_REG     *((volatile uint8*) 0x29)    /* USART Baud Rate Register (Low byte) */
#define UBRRH_REG     *((volatile uint8*) 0x40)    /* USART Baud Rate Register (High byte, same address as UCSRC with URSEL cleared) */
/***********************************************************************************************/

/********************************** UCSRA Register Bits **********************************/
#define RXC     7     /* USART Receive Complete */
#define TXC     6     /* USART Transmit Complete */
#define UDRE    5     /* USART Data Register Empty */
#define FE      4     /* Frame Error */
#define DOR     3     /* Data OverRun */
#define PE      2     /* Parity Error */
#define U2X     1     /* Double the USART Transmission Speed */
#define MPCM    0     /* Multi-processor Communication Mode */

/********************************** UCSRB Register Bits **********************************/
#define RXCIE   7     /* RX Complete Interrupt Enable */
#define TXCIE   6     /* TX Complete Interrupt Enable */
#define UDRIE   5     /* Data Register Empty Interrupt Enable */
#define RXEN    4     /* Receiver Enable */
#define TXEN    3     /* Transmitter Enable */
#define UCSZ2   2     /* Character Size (bit 2 for 8-bit mode) */
#define RXB8    1     /* Receive Data Bit 8 */
#define TXB8    0     /* Transmit Data Bit 8 */

/********************************** UCSRC Register Bits **********************************/
#define URSEL   7     /* Register Select */
#define UMSEL   6     /* USART Mode Select (Asynchronous/Synchronous) */
#define UPM1    5     /* Parity Mode (UPM1:0) */
#define UPM0    4
#define USBS    3     /* Stop Bit Select (1 stop bit or 2) */
#define UCSZ1   2     /* Character Size (bit 1 for 8-bit mode) */
#define UCSZ0   1     /* Character Size (bit 0 for 8-bit mode) */
#define UCPOL   0     /* Clock Polarity (for synchronous mode only) */

#endif /* MCAL_UART_UART_REGISTERS_H_ */
