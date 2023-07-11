#include <avr/io.h>
#include <avr/interrupt.h>

#include "SPI.h"

// Initialize external interrupt 1 (INT1) on pin PD3
void INT1_init()
{
    // Set PD3 as input
    DDRD &= ~(1 << DDD3);
    // Enable internal pull-up resistor on PD3
    PORTD |= (1 << PORTD3);
    // Trigger interrupt on falling edge
    MCUCR |= (1 << ISC11) | (0 << ISC10);
    // Enable external interrupt 1
    GICR |= (1 << INT1);
    // Enable global interrupts
    sei();
}

// External interrupt 1 (INT1) service routine to handle button press on PD3 (INT1) pin
ISR(INT1_vect)
{
    SPI_transmit('!' + 252);
}