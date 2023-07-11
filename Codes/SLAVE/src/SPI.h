#include <avr/io.h>
#include <avr/interrupt.h>

#include "password.h"

int temperature = 0;
int light = 0;

void SPI_init()
{
    // Set MISO as output, all others as input (MOSI, SCK, SS)
    DDRB |= (0 << DDB7) | (1 << DDB6) | (0 << DDB5) | (0 << DDB4) | (1 << DDB3);
    // Enable SPI, Enable Interrupt, Set as Slave, Set Clock Rate to fck/128
    SPCR |= (1 << SPIE) | (1 << SPE) | (0 << MSTR) | (1 << SPR1) | (1 << SPR0);
    // Enable Global Interrupts (I-bit) in SREG (Status Register)
    sei();
}

// SPI Interrupt Service Routine
ISR(SPI_STC_vect)
{
    int received_data = SPDR; // Read the received data
    if (!is_access_granted)
    {
        char key = received_data - 252;
        if (key == '#')
            delete_last_char(&typed_password);
        else if (key == '*')
            check_password(&typed_password);
        else if (key == '!')
            toggle_password_visibility();
        else if (key != '\0')
        {
            append_char_to_string(&typed_password, key); // Append the key to the typed_password string
            if (is_visible)
                LCD_write(key);
            else
                LCD_write('*');
        }
    }
    else
    {
        if (0 <= received_data && received_data <= 150)
            temperature = received_data;
        else if (151 <= received_data && received_data <= 252)
            light = received_data - 151;
    }
}
