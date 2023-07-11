#include <string.h>

#include <avr/io.h>
#include <util/delay.h>

#define LCD_DATA PORTC
#define ctrl PORTD

void LCD_cmd(unsigned char cmd)
{
    LCD_DATA = cmd;
    ctrl = 0x04; // Register Select = 0, Read/Write = 0, Enable = 1
    _delay_ms(1);
    ctrl = 0x00; // Enable = 0
    _delay_ms(1);
    return;
}

void init_LCD(void)
{
    LCD_cmd(0x38); // 8-bit mode
    _delay_ms(1);
    LCD_cmd(0x01); // clear the screen
    _delay_ms(1);
    LCD_cmd(0x0E); // turn on the cursor
    // LCD_cmd(0x0f);         // make cursor blinking
    _delay_ms(1);
    LCD_cmd(0x80); // move cursor to the first place of the first row
    _delay_ms(1);
    return;
}

void LCD_write(unsigned char data)
{
    LCD_DATA = data;
    ctrl = 0x05; // Register Select = 1, Read/Write = 0, Enable = 1
    _delay_ms(1);
    ctrl = 0x01; // Enable = 0
    _delay_ms(50);
    return;
}

void LCD_write_string(char *string)
{
    LCD_cmd(0x01); // Clear the screen
    for (int character_index = 0; character_index < strlen(string); character_index++)
        LCD_write(string[character_index]);
}

void LCD_init()
{
    DDRC |= (1 << DDC7) | (1 << DDC6) | (1 << DDC5) | (1 << DDC4) | (1 << DDC3) | (1 << DDC2) | (1 << DDC1) | (1 << DDC0);
    DDRD |= (1 << DDD2) | (1 << DDD1) | (1 << DDD0);
    init_LCD();
}

void LCD_delete_last_char()
{
    LCD_cmd(0x10);  // Move the cursor to the left
    LCD_write(' '); // Write a space
    LCD_cmd(0x10);  // Move the cursor to the left
}
