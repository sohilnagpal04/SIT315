#include "PinChangeInt.h"

#define PIR 2
#define PIR2 11
#define SOIL 3

const int led_pin = PB5;

const uint16_t timer1_load = 0;
const uint16_t timer1_compare = 31250;

void setup()
{
    Serial.begin(9600);

    pinMode(PIR, INPUT);
    pinMode(PIR2, INPUT);
    pinMode(SOIL, INPUT);

    DDRB |= (1 << led_pin);

    attachInterrupt(digitalPinToInterrupt(PIR), externalInterrupt1, CHANGE);
    attachInterrupt(digitalPinToInterrupt(SOIL), externalInterrupt2, RISING);
    attachPinChangeInterrupt(PIR2, externalInterrupt3, CHANGE);

    TCCR1A = 0;

    TCCR1B &= ~(1 << WGM13);
    TCCR1B |= (1 << WGM12);

    TCCR1B |= (1 << CS12);
    TCCR1B &= ~(1 << CS11);
    TCCR1B |= (1 << CS10);

    TCNT1 = timer1_load;
    OCR1A = timer1_compare;

    TIMSK1 = (1 << OCIE1A);

    sei();
}

void loop()
{
    delay(1000);
}

ISR(TIMER1_COMPA_vect)
{
    PORTB ^= (1 << led_pin);
    Serial.println("A Timer interrupt has occured");
}

void externalInterrupt1()
{
    Serial.println("Interrupt (PIR1)");
}

void externalInterrupt2()
{
    Serial.println("Interrupt (Soil Moisture)");
}

void externalInterrupt3()
{
    Serial.println("Interrupt (PIR2)");
}