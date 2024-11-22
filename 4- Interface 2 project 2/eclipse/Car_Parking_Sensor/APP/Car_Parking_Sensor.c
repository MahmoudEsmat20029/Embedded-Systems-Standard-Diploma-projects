/************************************************************************************
 * Module		: Car Parking Sensor
 * File Name	: Car_Parking_Sensor.c
 * Author		: Mahmoud 3smat
 * Created on	: 8/10/2024
 * Description	: Main application for the Car Parking Sensor using ATmega32
 ************************************************************************************/
#include "Car_Parking_Sensor.h"

int main(void) {
    uint16 distance = 0;

    /* Initialize components */
    Ultrasonic_init();
    Buzzer_init();
    LEDS_init();
    LCD_init();

    /* Display welcome message */
    LCD_displayString("Car Parking Sensor");
    _delay_ms(1000);
    LCD_clearScreen();

    sei();	/* I-bit to enable interrupts --> ICU */

    while (1)
    {
        /* Read and validate the distance from the Ultrasonic sensor */
        distance = (Ultrasonic_readDistance() + 1) / 2;
        if (50 < distance)
        {
            distance = 0; /* Reset to 0 if the distance is invalid */
        }

        /* Display distance on the LCD */
        LCD_displayStringRowColumn(0, 0, "Dist = ");
        LCD_intgerToString(distance);
        LCD_displayString(" cm");

        /* Ensure actions are taken only when distance is non-zero */
        if (0 < distance)
        {
            /* Handle actions based on distance */
            if (0 < distance && 5 >= distance)
            {
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_on(LED_BLUE);
                Buzzer_on();
                LCD_clearScreen();
                LCD_displayStringRowColumn(0, 0, "Stop!");
                _delay_ms(1000);
                LCD_displayStringRowColumn(0, 0, "Dist = ");
                LCD_intgerToString(distance);
                LCD_displayString(" cm");
                _delay_ms(1000);
            }
            else if (5 < distance && 10 >= distance)
            {
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_on(LED_BLUE);
                Buzzer_off();
            }
            else if (10 < distance && 15 >= distance)
            {
                LED_on(LED_RED);
                LED_on(LED_GREEN);
                LED_off(LED_BLUE);
                Buzzer_off();
            }
            else if (15 < distance && 20 >= distance)
            {
                LED_on(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
                Buzzer_off();
            }
            else
            {
                LED_off(LED_RED);
                LED_off(LED_GREEN);
                LED_off(LED_BLUE);
                Buzzer_off();
            }
        }
        else
        {
            /* Turn off all LEDs and the buzzer if the distance is zero */
            LED_off(LED_RED);
            LED_off(LED_GREEN);
            LED_off(LED_BLUE);
            Buzzer_off();
        }

        /* Small delay for stabilization */
        _delay_ms(200);
    }
}
