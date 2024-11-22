/*
 *  Project title: StopWatch dual trace [increment - decrement]
 *  Created on   : 11/9/2024
 *  Author       : Mahmoud Esmat
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define FULL_SECONDS 60
#define FULL_MINUTES 60
#define FULL_HOURS   24

typedef unsigned char uint8;	/* 8-bit unsigned integer */
enum bool{false, true};

/* Global Variables */
volatile uint8 num_sec = 0;
volatile uint8 num_min = 0;
volatile uint8 num_hr  = 0;

/* Variables for button press flags */
volatile uint8 Increment_hr_was_pressed  = false, Decrement_hr_was_pressed  = false;
volatile uint8 Increment_min_was_pressed = false, Decrement_min_was_pressed = false;
volatile uint8 Increment_sec_was_pressed = false, Decrement_sec_was_pressed = false;

/* Timer1 Compare Match A Interrupt Service Routine */
ISR(TIMER1_COMPA_vect)
{
	if (PINB & (1<<PB7))	/* Check if timer is in increment mode */
	{
		PORTD |= (1<<PD4);	/* RED LED ON */
		PORTD &= ~(1<<PD5);	/* YELLOW LED OFF */
		PORTD &= ~(1<<PD0); /* BUZZER OFF */

		num_sec++;	/* Always increment after 1 Second */
		if(FULL_SECONDS == num_sec)	/* one Minutes complete */
		{
			num_sec = 0;
			num_min++;
		}
		if(FULL_MINUTES == num_min)	/* one Hour complete */
		{
			num_min = 0;
			num_hr++;
		}
		if(FULL_HOURS == num_hr)	/* one Day complete */
		{
			num_hr = 0;
		}
	}
	else	/* Decrement mode */
	{
		PORTD &= ~(1<<PD4);	/* RED LED OFF */
		PORTD |= (1<<PD5);	/* YELLOW LED ON */

		if(num_sec)	/* until not decrease to {num_sec = -1} */
			num_sec--;

		if(!num_sec && !num_min && !num_hr)	/* if seconds & minutes & hours are zeros */
		{
			num_sec = num_min = num_hr = 0;	/* don't change */
			PORTD |= (1<<PD0);  /* BUZZER ON */
		}
		else if(!num_sec && !num_min)	/* until not reach to {num_min = -1} */
		{
			num_hr--;
			num_min = FULL_MINUTES - 1;
			num_sec = FULL_SECONDS - 1;
		}
		else if(!num_sec)
		{
			num_sec = FULL_SECONDS - 1;
			num_min--;
		}
	}
}

/* External INT0 Interrupt Service Routine {Reset Timer} */
ISR(INT0_vect)
{
	num_sec = num_min = num_hr = 0;	/* Reset all 7-Segment */
}

/* External INT1 Interrupt Service Routine {Pause Timer} */
ISR(INT1_vect)
{
	TCCR1B &= ~((1<<CS10) | (1<<CS11) | (1<<CS12));  /* Stop timer1 */
}

/* External INT2 Interrupt Service Routine {Resume Timer} */
ISR(INT2_vect)
{
	TCCR1B |= (1<<CS10) | (1<<CS12);  /* Resume timer1 by Prescaler */
}

/* Timer1 Configuration */
void Timer1_clock(void)
{
	TCCR1A = (1<<FOC1A);	/* NO-PWM */
	/*
	 * CS10 & CS12 for prescaler 1024
	 * WGM12 for compare mode
	 */
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);
	TCNT1  = 0;	/* Start from 0 */
	OCR1A  = 15625;	/* Compare match value for 1-second interval */
	TIMSK |= (1<<OCIE1A);	/* Enable Timer1 interrupt */
}

/* INT0 Configuration for Reset */
void INT0_Reset(void)
{
	DDRD  &= ~(1<<PD2);	/* Set pin 2 port D as input pin */
	PORTD |= (1<<PD2);	/* Enable internal pull-up resistor on PD2 */
	MCUCR |= (1<<ISC01);	/* Trigger falling edge */
	GICR  |= (1<<INT0);	/* Enable INT0 interrupt */
}

/* INT1 Configuration for Pause */
void INT1_Pause(void)
{
	DDRD  &= ~(1<<PD3);	/* Set pin 3 port D as input pin */
	MCUCR |= (1<<ISC10) | (1<<ISC11);	/* Trigger rising edge */
	GICR  |= (1<<INT1);	/* Enable INT1 interrupt */
}

/* INT2 Configuration for Resume */
void INT2_Resume(void)
{
	DDRB   &= ~(1<<PB2);	/* Set pin 2 port B as input pin */
	PORTD  |= (1<<PB2);	/* Enable internal pull-up resistor on PB2 */
	MCUCSR &= ~(1<<ISC2);	/* Trigger on falling edge */
	GICR   |= (1<<INT2);	/* Enable INT2 interrupt */
}

/* Function to increment hours */
void Increment_hr(void)
{
    /* Check if the increment button for hours is pressed and was not pressed before */
    if (!(PINB & (1<<PB1)) && !Increment_hr_was_pressed)
    {
        num_hr++; /* Increment the hour */
        if(FULL_HOURS == num_hr) /* If hours reach 24, reset to 0 */
        {
            num_hr = 0;
        }
        Increment_hr_was_pressed = true; /* Set flag to know the button was pressed */
    }
    /* Reset the flag when the button is released */
    else if (PINB & (1<<PB1))
    {
        Increment_hr_was_pressed = false;
    }
}

/* Function to decrement hours */
void Decrement_hr(void)
{
    /* Check if the decrement button for hours is pressed and was not pressed before */
    if (!(PINB & (1<<PB0)) && !Decrement_hr_was_pressed)
    {
        if (!num_hr) /* If hours are 0, set to 23 */
        {
            num_hr = FULL_HOURS - 1;
        }
        else
        {
            num_hr--; /* Decrement the hour */
        }
        Decrement_hr_was_pressed = true; /* Set flag to know the button was pressed */
    }
    /* Reset the flag when the button is released */
    else if (PINB & (1<<PB0))
    {
        Decrement_hr_was_pressed = false;
    }
}

/* Function to increment minutes */
void Increment_min(void)
{
    /* Check if the increment button for minutes is pressed and was not pressed before */
    if (!(PINB & (1<<PB4)) && !Increment_min_was_pressed)
    {
        num_min++; /* Increment the minute */
        if (FULL_MINUTES == num_min) /* If minutes reach 60, reset to 0 */
        {
            num_min = 0;
        }
        Increment_min_was_pressed = true; /* Set flag to know the button was pressed */
    }
    /* Reset the flag when the button is released */
    else if (PINB & (1<<PB4))
    {
        Increment_min_was_pressed = false;
    }
}

/* Function to decrement minutes */
void Decrement_min(void)
{
    /* Check if the decrement button for minutes is pressed and was not pressed before */
    if (!(PINB & (1<<PB3)) && !Decrement_min_was_pressed)
    {
        if (!num_min) /* If minutes are 0, set to 59 */
        {
            num_min = FULL_MINUTES - 1;
        }
        else
        {
            num_min--; /* Decrement the minute */
        }
        Decrement_min_was_pressed = true; /* Set flag to know the button was pressed */
    }
    /* Reset the flag when the button is released */
    else if (PINB & (1<<PB3))
    {
        Decrement_min_was_pressed = false;
    }
}

/* Function to increment seconds */
void Increment_sec(void)
{
    /* Check if the increment button for seconds is pressed and was not pressed before */
    if (!(PINB & (1<<PB6)) && !Increment_sec_was_pressed)
    {
        num_sec++; /* Increment the second */
        if (FULL_SECONDS == num_sec) /* If seconds reach 60, reset to 0 */
        {
            num_sec = 0;
        }
        Increment_sec_was_pressed = true; /* Set flag to know the button was pressed */
    }
    /* Reset the flag when the button is released */
    else if (PINB & (1<<PB6))
    {
        Increment_sec_was_pressed = false;
    }
}

/* Function to decrement seconds */
void Decrement_sec(void)
{
    /* Check if the decrement button for seconds is pressed and was not pressed before */
    if (!(PINB & (1<<PB5)) && !Decrement_sec_was_pressed)
    {
        if (!num_sec) /* If seconds are 0, set to 59 */
        {
            num_sec = FULL_SECONDS - 1;
        }
        else
        {
            num_sec--; /* Decrement the second */
        }
        Decrement_sec_was_pressed = true; /* Set flag to indicate the button was pressed */
    }
    /* Reset the flag when the button is released */
    else if (PINB & (1<<PB5))
    {
        Decrement_sec_was_pressed = false;
    }
}

/* Seven Segment Display Function */
void Display(void)
{
	while(1)
	{
		/* Call all buttons function */
		Increment_hr();
		Decrement_hr();
		Increment_min();
		Decrement_min();
		Increment_sec();
		Decrement_sec();

		/* Display hours, minutes, and seconds on seven-segment display */
		PORTA = (PORTA & 0xC0) | 0x20;  /* Enable the first display */
		PORTC = (PORTC & 0xF0) | ((num_sec % 10) & 0x0F); /* Example: 46 -> {46 % 10 = '6'} */
		_delay_ms(2);

		PORTA = (PORTA & 0xC0) | 0x10;  /* Enable the second display */
		PORTC = (PORTC & 0xF0) | ((num_sec / 10) & 0x0F); /* Example: 46 -> {46 / 10 = '4'} */
		_delay_ms(2);

		PORTA = (PORTA & 0xC0) | 0x08;  /* Enable the third display */
		PORTC = (PORTC & 0xF0) | ((num_min % 10) & 0x0F); /* Example: 46 -> {46 % 10 = '6'} */
		_delay_ms(2);

		PORTA = (PORTA & 0xC0) | 0x04;  /* Enable the fourth display */
		PORTC = (PORTC & 0xF0) | ((num_min / 10) & 0x0F); /* Example: 46 -> {46 / 10 = '4'} */
		_delay_ms(2);

		PORTA = (PORTA & 0xC0) | 0x02;  /* Enable the fifth display */
		PORTC = (PORTC & 0xF0) | ((num_hr % 10) & 0x0F); /* Example: 16 -> {16 % 10 = '6'} */
		_delay_ms(2);

		PORTA = (PORTA & 0xC0) | 0x01;  /* Enable the sixth display */
		PORTC = (PORTC & 0xF0) | ((num_hr / 10) & 0x0F); /* Example: 16 -> {16 / 10 = '1'} */
		_delay_ms(2);
	}
}

/* Ports Configuration */
void Ports_configuration(void)
{
	/* Ports Configuration */
	DDRA  |= 0x3F;	/* Set 1st six pins of PORTA as output */
	PORTA &= 0xC0;	/* Set 1st six pins port A off */

	DDRC  |= 0x0F;	/* Set 1st four pins of PORTC as output */
	PORTC &= 0xF0;	/* Set 1st four pins port C off */

	DDRD  |= (1<<PD0) | (1<<PD4) | (1<<PD5); /* Set pins 0,4,5 port D as output for BUZZER and LEDs */
	PORTD &= ~(1<<PD0) & ~(1<<PD5);	/* Set BUZZER and yellow LED OFF */
	PORTD |= (1<<PD4);	/* Set red LED initially on */

	DDRB  &= 0x00;	/* set all pins port B as input pins */
	PORTB |= 0xFF;	/* Activate the internal pull up resistor at all pins port B */
}

/* Main Function */
int main(void)
{
	Ports_configuration();	/* Ports Configuration */

	/* Initialize Timer and Interrupts */
	Timer1_clock();
	INT0_Reset();
	INT1_Pause();
	INT2_Resume();

	/* Enable global interrupts I-bit {SREG |= (1<<7)} */
	sei();

	/* Start Display Function */
	Display();

	return 0;
}
