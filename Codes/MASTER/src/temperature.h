#include <avr/io.h>
#include <avr/interrupt.h>

void LM35_ADC_init()
{
    ADMUX = (0 << REFS1) | (1 << REFS0) | (0 << ADLAR) | (0 << MUX3) | (0 << MUX2) | (0 << MUX1) | (0 << MUX0);
    ADCSRA |= (1 << ADEN) | (0 << ADSC) | (1 << ADATE) | (0 << ADIF) | (0 << ADIE) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

int read_temperature()
{
    LM35_ADC_init();

    ADCSRA |= (1 << ADSC) | (1 << ADIF);

    while ((ADCSRA & (1 << ADIF)) == 0)
        ;

    return ADCW * (0.48828125);
}
