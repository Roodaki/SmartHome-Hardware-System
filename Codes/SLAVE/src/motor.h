#include <avr/io.h>

double heater_duty_cycle = 0;
double cooler_duty_cycle = 0;
double light_duty_cycle = 0;

void temperature_motor_init()
{
    // Set PD4 and PD5 pins as output
    DDRD |= (1 << DDD4) | (1 << DDD5);

    // Set Timer1 to Fast PWM mode, non-inverted output
    TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM10);
    TCCR1B |= (1 << WGM12) | (1 << CS11);

    // Set PWM pins as non-inverted
    TCCR1A &= ~(1 << COM1A0);
    TCCR1A &= ~(1 << COM1B0);
}

void light_motor_init()
{
    // Set OC2 pin as output
    DDRD |= (1 << DDD7);

    // Set Timer2 to Fast PWM mode, non-inverted output
    TCCR2 |= (1 << COM21) | (1 << WGM20) | (1 << WGM21);

    // Set PWM pin as non-inverted
    TCCR2 &= ~(1 << COM20);

    // Set prescaler to 8 for desired PWM frequency
    TCCR2 |= (1 << CS21);
}

void motors_init()
{
    temperature_motor_init();
    light_motor_init();
}

void temperature_motors_control(int temperature)
{
    if (25 <= temperature && temperature <= 55)
    {
        cooler_duty_cycle = 50 + ((temperature - 25) / 5) * 10;
        heater_duty_cycle = 0;
    }
    else if (0 <= temperature && temperature <= 20)
    {
        heater_duty_cycle = 100 - ((temperature - 0) / 5) * 25;
        cooler_duty_cycle = 0;
    }
    else
    {
        cooler_duty_cycle = 0;
        heater_duty_cycle = 0;
    }

    OCR1A = (cooler_duty_cycle / 100) * 255;
    OCR1B = (heater_duty_cycle / 100) * 255;
}

void light_motor_control(int light)
{
    if (0 < light && light < 25)
    {
        light_duty_cycle = 100;
    }
    else if (25 <= light && light < 50)
    {
        light_duty_cycle = 75;
    }
    else if (50 <= light && light < 75)
    {
        light_duty_cycle = 50;
    }
    else if (75 <= light && light <= 100)
    {
        light_duty_cycle = 25;
    }
    else
    {
        light_duty_cycle = 0;
    }

    OCR2 = (light_duty_cycle / 100) * 255;
}

void motors_control(int temperature, int light)
{
    temperature_motors_control(temperature);
    light_motor_control(light);
}