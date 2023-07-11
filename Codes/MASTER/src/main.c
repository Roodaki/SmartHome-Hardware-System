#include <stdlib.h>

#include "INT1.h"
#include "temperature.h"
#include "keypad.h"
#include "LDR.h"

int main()
{
    keypad_init();
    SPI_init();
    INT1_init();

    while (1)
    {
        if ((PINB >> PINB3) & 1)
        {
            SPI_transmit(read_temperature());
            _delay_ms(1);
            SPI_transmit(read_light() + 151);
            _delay_ms(1);
        }
        else
        {
            char key = keypad_read();
            if (key != '\0')
                SPI_transmit(key + 252);
        }
        _delay_ms(1);
    }

    return 0;
}
