/************************************************************************************
 * File Name	: Based_Door_Locker_Security_System_p2.h
 * Author		: Mahmoud 3smat
 * Created on	: 27/10/2024
 * Description	: Header file for the application
 ************************************************************************************/
#ifndef APP_BASED_DOOR_LOCKER_SECURITY_SYSTEM_P2_H_
#define APP_BASED_DOOR_LOCKER_SECURITY_SYSTEM_P2_H_

/* Include necessary libraries and modules */
#include "../HAL/External_EEPROM/external_eeprom.h"	/* External EEPROM for password storage */
#include "../HAL/DC_MOTOR/dc_motor.h"	/* DC Motor for door control */
#include "../HAL/BUZZER/buzzer.h"		/* Buzzer for alerts */
#include "../MCAL/Timer/timer.h"	/* Timer for managing timing functions */
#include "../MCAL/UART/uart.h"		/* UART for communication */
#include "../MCAL/I2C/i2c.h"		/* I2C protocol for data transfer */
#include "../HAL/PIR/pir.h"		/* PIR sensor for motion detection */
#include <util/delay.h>		/* Delay for timing functions */

/* Define constants */
#define EEPROM_ADDRESS			0x0000	/* EEPROM address for storing password */
#define PASSWORD_MATCHED 		1		/* Indicator for matched password */
#define PASSWORD_UNMATCHED 		0		/* Indicator for unmatched password */
#define PASSWORD_LENGTH 		5		/* Length of password */
#define HMI_ECU_READY			1		/* Flag indicating HMI ECU readiness */
#define CONTROL_ECU_READY		1		/* Flag indicating Control ECU readiness */
#define MAX_TRY_COUNTER			3		/* Maximum password attempts allowed */
#define BOUD_RATE				9600	/* Baud rate for UART communication */

/* Timer configuration structure */
Timer_ConfigType timer1_configurations = {
		INITIAL_VALUE,
		TICKS_PER_SECOND,
		TIMER1,
		TIMER_CLOCK_1024,
		TIMER_COMP_MODE
};

/*******************************************************************************

 *                      Functions Prototypes                                   *
 *******************************************************************************/
/* Function to store the password */
void Step1_StorePassword(void);

/* Function for main options after password is set */
void Step2_MainOptions(void);

/* Function to unlock the door */
void Step3_UnlockDoor(void);

/* Function to check if the entered password matches the stored password */
uint8 Step4_CheckPassword(uint8* password, uint8* password_confirm);

/* Function to handle unmatched password attempts */
void Step5_UnmatchedPasswordHandling(void);

/* Function to receive the password via UART */
void receivePassword(uint8* password);

/* Function to increase timer ticks */
void timer_increase_ticks(void);

#endif /* APP_BASED_DOOR_LOCKER_SECURITY_SYSTEM_P2_H_ */
