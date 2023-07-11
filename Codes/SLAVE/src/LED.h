#include <avr/io.h>
#include <util/delay.h>

void LED_init()
{
    // set PB1 and PB2 as output pins (LEDs) and set them to low (off) initially
    DDRB |= (1 << DDB2) | (1 << DDB1);
    PORTB &= ~((1 << PORTB2) | (1 << PORTB1));
}

void LED_control(int temperature)
{
    // If the temperature is below 5 degrees, make the blue LED blink every 2 seconds (1 second on, 1 second off)
    if (temperature < 3)
    {
        PORTB |= (1 << PB1);
        _delay_ms(50);
        PORTB &= ~(1 << PB1);
    }
    // If the temperature is above 55 degrees, make the red LED blink every 2 seconds (1 second on, 1 second off)
    else if (temperature > 55)
    {
        PORTB |= (1 << PB2);
        _delay_ms(50);
        PORTB &= ~(1 << PB2);
    }
    // If the temperature is between 5 and 55 degrees, turn off both LEDs
    else
    {
        PORTB &= ~((1 << PORTB2) | (1 << PORTB1));
    }
}