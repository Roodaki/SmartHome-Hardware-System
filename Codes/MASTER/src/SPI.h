#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Initialize SPI Master Device (with SPI interrupt)
void SPI_init()
{
    // Set MOSI, SCK, SS as Output (PB5, PB7, PB4) and MISO as Input (PB6)
    DDRB |= (1 << DDB7) | (0 << DDB6) | (1 << DDB5) | (1 << DDB4);
    // Activate Pull-Up on MISO (PB6) to set it to high level (1)
    PORTB |= (1 << PORTB4);

    // Enable SPI, Enable SPI Interrupt, Set as Master Device, Set SCK Frequency to Fosc/128 (125kHz)
    SPCR |= (1 << SPIE) | (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);

    // Enable Global Interrupts
    sei();
}

void SPI_transmit(int data)
{
    // Start Transmission
    SPDR = data;
}

// SPI Interrupt Service Routine
ISR(SPI_STC_vect)
{
    PORTB |= (1 << PORTB4); // Deselect Slave
    while (((SPSR >> SPIF) & 1) == 0)
        ;
    PORTB &= ~(1 << PORTB4); // Select Slave
}
