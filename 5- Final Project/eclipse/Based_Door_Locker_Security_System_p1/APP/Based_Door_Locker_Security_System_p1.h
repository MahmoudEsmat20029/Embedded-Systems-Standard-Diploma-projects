/************************************************************************************
 * File Name	: Based_Door_Locker_Security_System_p1.h
 * Author		: Mahmoud 3smat
 * Created on	: 26/10/2024
 * Description	: Header file for the application
 ************************************************************************************/

#ifndef BASED_DOOR_LOCKER_SECURITY_SYSTEM_P1_H_
#define BASED_DOOR_LOCKER_SECURITY_SYSTEM_P1_H_

/* Include necessary libraries and modules */
#include "../HAL/keypad/keypad.h"	/* Keypad interface for user input */
#include "../MCAL/Timer/timer.h"	/* Timer for managing timing functions */
#include "../MCAL/UART/uart.h"		/* UART interface for ECU communication */
#include "../LIB/std_types.h"		/* Standard data types */
#include "../HAL/LCD/lcd.h"			/* LCD interface for display */
#include <util/delay.h>				/* Delay functions */
#include <avr/io.h>					/* AVR microcontroller definitions */
#include <string.h>					/* To use string comparison functions like strcmp */

/* Define constants */
#define HMI_ECU_READY			1	/* Signal indicating HMI ECU readiness */
#define CONTROL_ECU_READY		1	/* Signal indicating Control ECU readiness */
#define PASSWORD_MATCHED 		1	/* Value for successful password match */
#define PASSWORD_UNMATCHED 		0	/* Value for unsuccessful password match */
#define PASSWORD_LENGTH 		5	/* Maximum length of the password */
#define MAX_TRY_COUNTER			3	/* Maximum allowed password attempts */
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

/* Function to create a new password */
void Step1_CreatePassword(void);

/* Function for main options after password is set */
void Step2_MainOptions(void);

/* Function to unlock the door */
void Step3_UnlockDoor(void);

/* Function to change the existing password */
void Step4_ChangePassword(void);

/* Function to handle unmatched password attempts */
void Step5_UnmatchedPasswordHandling(void);

/* Function to transmit the password */
void transmittePassword(uint8 *pass);

/* Function to receive the password */
void receivePassword(uint8* password);

/* Function to increase timer ticks */
void timer_increase_ticks(void);

#endif /* BASED_DOOR_LOCKER_SECURITY_SYSTEM_P1_H_ */
