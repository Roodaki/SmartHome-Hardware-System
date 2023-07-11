#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "LCD.h"

#define PASSWORD "1234"

char *typed_password = NULL;
bool is_visible = true;
bool is_access_granted = false;

// Convert an integer to a string and return the string
char *int_to_str(int number)
{
    char *string = (char *)malloc(4);
    sprintf(string, "%d", number);
    return string;
}

// Delete the last character from the string and from the LCD screen if the string is not empty and not NULL
void delete_last_char(char **string)
{
    // From the LCD
    LCD_delete_last_char();
    // From the String
    if (*string != NULL && **string != '\0')
    {
        int length = strlen(*string);
        char *new_string = (char *)realloc(*string, length);
        if (new_string != NULL)
        {
            *string = new_string;
            (*string)[length - 1] = '\0';
        }
    }
}

// Append the character to the string if it is not '#' or '*'
void append_char_to_string(char **string, char char_to_append)
{
    if (char_to_append != '#' && char_to_append != '*')
    {
        if (*string == NULL)
        {
            *string = (char *)malloc(2);
            (*string)[0] = char_to_append;
            (*string)[1] = '\0';
        }
        else
        {
            int length = strlen(*string);
            *string = (char *)realloc(*string, length + 2);
            (*string)[length] = char_to_append;
            (*string)[length + 1] = '\0';
        }
    }
}

void check_password(char **typed_password)
{
    if (strcmp(*typed_password, PASSWORD) == 0)
    {
        LCD_write_string("ACCESS IS GRANTED.");
        is_access_granted = true;
        PORTB |= (1 << PORTB3);
    }
    else
    {
        LCD_write_string("WRONG PASSWORD!");
        *typed_password = NULL;
    }
    LCD_init();
}

void toggle_password_visibility()
{
    is_visible = !is_visible;
    LCD_init();
    if (is_visible)
        LCD_write_string(typed_password);
    else
        for (int i = 0; i < strlen(typed_password); i++)
            LCD_write('*');
}