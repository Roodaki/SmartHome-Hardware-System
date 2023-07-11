#include "SPI.h"
#include "LED.h"
#include "motor.h"

int main()
{
    // Initializations
    LCD_init();
    SPI_init();
    motors_init();
    LED_init();

    // Loop
    while (1)
    {
        if (is_access_granted)
        {
            LCD_write_string(int_to_str(temperature));
            LCD_write_string(int_to_str(light));

            motors_control(temperature, light);
            LED_control(temperature);
        }
        _delay_ms(1);
    }

    return 0;
}
