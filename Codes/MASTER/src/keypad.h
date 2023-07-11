#include <avr/io.h>

void keypad_init()
{
    // Set column pins as outputs and row pins as inputs
    DDRC |= (1 << DDC7) | (1 << DDC6) | (1 << DDC5);
    DDRC &= ~(1 << DDC3) & ~(1 << DDC2) & ~(1 << DDC1) & ~(1 << DDC0);
    // Enable pull-up resistors for the row pins
    PORTC |= (1 << PORTC3) | (1 << PORTC2) | (1 << PORTC1) | (1 << PORTC0);
}

char keypad_read()
{
    // Define the keypad matrix
    char keypad[4][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}};

    // Array to hold the corresponding row and column values for each key
    int row_pins[4] = {PINC0, PINC1, PINC2, PINC3};
    int column_pins[3] = {PINC5, PINC6, PINC7};

    // Loop through each column and check for key press
    for (int column = 0; column < 3; column++)
    {
        // Activate current column by making it low
        PORTC &= ~(1 << column_pins[column]);
        // Check the row pins for a low signal
        for (int row = 0; row < 4; row++)
            if (!(PINC & (1 << row_pins[row])))
                // Check again to confirm key press
                if (!(PINC & (1 << row_pins[row])))
                    // Return the corresponding keypad character
                    return keypad[row][column];
        // Deactivate current column by making it high
        PORTC |= (1 << column_pins[column]);
    }

    // No key pressed
    return '\0';
}
