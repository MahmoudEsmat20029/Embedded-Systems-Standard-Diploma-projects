/************************************************************************************
 * Module       : Timer
 * File Name    : timer.c
 * Author       : Mahmoud 3smat
 * Created on   : 26/10/2024
 * Description  : Source file for the Timer AVR driver
 ************************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

#include "../../LIB/std_types.h"
#include "../../LIB/common_macros.h"
#include <avr/interrupt.h>
#include <avr/io.h>

/*******************************************************************************
 *                          	 Definitions                                   *
 *******************************************************************************/
/* Number of ticks per second using 8 MHz and prescaler of 64 */
#define TICKS_PER_SECOND	7812	/* 77812.5 */
/* Initial value for Timer (used during setup) */
#define INITIAL_VALUE	0

/*******************************************************************************
 *                          Type Definitions                                   *
 *******************************************************************************/
/* Enumeration to define Timer ID */
typedef enum {
	TIMER0, /* Timer 0 */
	TIMER1, /* Timer 1 */
	TIMER2  /* Timer 2 */
} Timer_ID_Type;

/* Enumeration to define Timer Clock Types */
typedef enum {
	TIMER_CLOCK_NO_CLK,	/* No clock source */
	TIMER_CLOCK_1,		/* Clock with no prescaling (1) */
	TIMER_CLOCK_8,		/* Clock with prescaler of 8 */
	TIMER_CLOCK_64,		/* Clock with prescaler of 64 */
	TIMER_CLOCK_256,	/* Clock with prescaler of 256 */
	TIMER_CLOCK_1024	/* Clock with prescaler of 1024 */
} Timer_ClockType;

/* Enumeration to define Timer Modes */
typedef enum {
	TIMER_NORMAL_MODE, /* Normal mode */
	TIMER_COMP_MODE,   /* Compare mode */
} Timer_ModeType;

/* Configuration structure for the Timer */
typedef struct {
	uint16 timer_InitialValue;		/* Initial value for the timer */
	uint16 timer_compare_value;		/* Compare value (used only in compare mode) */
	Timer_ID_Type timer_ID;			/* Timer ID */
	Timer_ClockType prescaler;		/* Timer clock type */
	Timer_ModeType timer_mode;		/* Timer mode */
} Timer_ConfigType;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/* Function to initialize the specified timer with CTC or normal mode */
void Timer_init(const Timer_ConfigType * Config_Ptr);

/* Function to de-initialize the specified timer and reset its settings */
void Timer_deInit(void);

/* Function to set the callback function for the specified timer to be executed by the ISR */
void Timer_setCallBack(void(*a_ptr)(void), Timer_ID_Type timer_ID);

#endif /* TIMER_H_ */
