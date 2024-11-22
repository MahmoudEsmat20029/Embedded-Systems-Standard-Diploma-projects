/************************************************************************************
 * Module       : Timer
 * File Name    : timer.c
 * Author       : Mahmoud 3smat
 * Created on   : 26/10/2024
 * Description  : Source file for the Timer AVR driver
 ************************************************************************************/
#include "timer.h"

/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Callback pointer for Timer 0 interrupt */
static volatile void (*g_callBackPtr_timer0)(void) = NULL_PTR;
/* Callback pointer for Timer 1 interrupt */
static volatile void (*g_callBackPtr_timer1)(void) = NULL_PTR;
/* Callback pointer for Timer 2 interrupt */
static volatile void (*g_callBackPtr_timer2)(void) = NULL_PTR;

/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
/* Timer 0 Capture Interrupt Service Routine */
ISR(TIMER0_CAPT_vect)
{
	if(g_callBackPtr_timer0 != NULL_PTR)
	{
		(*g_callBackPtr_timer0)();
	}
}

/* Timer 0 Compare Match Interrupt Service Routine */
ISR(TIMER0_COMP_vect)
{
	if(g_callBackPtr_timer0 != NULL_PTR)
	{
		(*g_callBackPtr_timer0)();
	}
}

/* Timer 1 Capture Interrupt Service Routine */
ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr_timer1 != NULL_PTR)
	{
		(*g_callBackPtr_timer1)();
	}
}

/* Timer 1 Compare Match Interrupt Service Routine */
ISR(TIMER1_COMPA_vect)
{
	if(g_callBackPtr_timer1 != NULL_PTR)
	{
		(*g_callBackPtr_timer1)();
	}
}

/* Timer 2 Capture Interrupt Service Routine */
ISR(TIMER2_CAPT_vect)
{
	if(g_callBackPtr_timer2 != NULL_PTR)
	{
		(*g_callBackPtr_timer2)();
	}
}

/* Timer 2 Compare Match Interrupt Service Routine */
ISR(TIMER2_COMP_vect)
{
	if(g_callBackPtr_timer2 != NULL_PTR)
	{
		(*g_callBackPtr_timer2)();
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void Timer_setCallBack(void(*a_ptr)(void), Timer_ID_Type timer_ID)
{
	switch (timer_ID)
	{
	case TIMER0:
		g_callBackPtr_timer0 = a_ptr;  /* Set the callback for Timer 0 */
		break;
	case TIMER1:
		g_callBackPtr_timer1 = a_ptr;  /* Set the callback for Timer 1 */
		break;
	case TIMER2:
		g_callBackPtr_timer2 = a_ptr;  /* Set the callback for Timer 2 */
		break;
	default:
		break;
	}
}

void Timer_init(const Timer_ConfigType * Config_Ptr)
{
	/* Initialize the timer counter based on the timer ID */
	switch (Config_Ptr->timer_ID)
	{
	case TIMER0:
		TCNT0 = Config_Ptr->timer_InitialValue;	/* Set initial value for Timer 0 */
		if (Config_Ptr->timer_mode == TIMER_COMP_MODE)
		{
			OCR0 = Config_Ptr->timer_compare_value;	/* Set compare value for Timer 0 */
			TIMSK |= (1<<OCIE0);		/* Enable Timer 0 Compare Match Interrupt */
		}
		else
		{
			TIMSK |= (1<<TOIE0);		/* Enable Timer 0 Overflow Interrupt */
		}
		TCCR0 |= (Config_Ptr->prescaler);		/* Set prescaler for Timer 0 */
		break;

	case TIMER1:
		TCNT1 = Config_Ptr->timer_InitialValue;	/* Set initial value for Timer 1 */
		if (Config_Ptr->timer_mode == TIMER_COMP_MODE)
		{
			OCR1A = Config_Ptr->timer_compare_value;	/* Set compare value for Timer 1 */
			TIMSK |= (1<<OCIE1A);		/* Enable Timer 1 Compare Match Interrupt */
			TCCR1B |= (1<<WGM12);		/* Set CTC mode for Timer 1 */
		}
		else
		{
			TIMSK |= (1<<TOIE1);		/* Enable Timer 1 Overflow Interrupt */
		}
		TCCR1B |= (Config_Ptr->prescaler);		/* Set prescaler for Timer 1 */
		TCCR1A = (1<<FOC1A) | (1<<FOC1B);		/* Set Fast PWM mode for Timer 1 */
		break;

	case TIMER2:
		TCNT2 = Config_Ptr->timer_InitialValue;		/* Set initial value for Timer 2 */
		if (Config_Ptr->timer_mode == TIMER_COMP_MODE)
		{
			OCR2 = Config_Ptr->timer_compare_value;		/* Set compare value for Timer 2 */
			TIMSK |= (1<<OCIE2);		/* Enable Timer 2 Compare Match Interrupt */
		}
		else
		{
			TIMSK |= (1<<TOIE2);		/* Enable Timer 2 Overflow Interrupt */
		}
		TCCR2 |= (Config_Ptr->prescaler);		/* Set prescaler for Timer 2 */
		break;

	default:
		break;
	}
}

void Timer_deInit(void)
{
	/* Reset the settings for Timer 0 */
	TCNT0 = 0;		/* Reset Timer 0 Counter */
	TCCR0 = 0;		/* Clear Timer 0 Control Register */
	TIMSK &= ~(1<<TOIE0);	/* Disable Timer 0 Overflow Interrupt */
	TIMSK &= ~(1<<OCIE0);	/* Disable Timer 0 Compare Match Interrupt */

	/* Reset the settings for Timer 1 */
	TCNT1 = 0;		/* Reset Timer 1 Counter */
	OCR1A = 0;		/* Reset Timer 1 Compare Match Value */
	TCCR1A = 0;		/* Clear Timer 1 Control Register A */
	TCCR1B = 0;		/* Clear Timer 1 Control Register B */
	TIMSK &= ~(1<<TOIE1);	/* Disable Timer 1 Overflow Interrupt */
	TIMSK &= ~(1<<OCIE1A);	/* Disable Timer 1 Compare Match Interrupt */

	/* Reset the settings for Timer 2 */
	TCNT2 = 0;		/* Reset Timer 2 Counter */
	OCR2 = 0;		/* Reset Timer 2 Compare Match Value */
	TCCR2 = 0;		/* Clear Timer 2 Control Register */
	TIMSK &= ~(1<<TOIE2);	/* Disable Timer 2 Overflow Interrupt */
	TIMSK &= ~(1<<OCIE2);	/* Disable Timer 2 Compare Match Interrupt */
}
