#include "LedControl.h"
#include <Arduino.h>

#define SET_BIT_STATE(x, bit, state) if(((x >> bit) & 1) != state) x ^= (1 << bit);

// BASIC LED CONTROL FUNCTIONS
void ledInit()
{
  DDRD |= B11110000;     // set digital pin 4 - 7 as output
  DDRB |= B00011111;     // set digital pin 8 - 12 as output
}

void setLedState(int led, int state)
{
  switch(led)
  {
    case 0: setLed0State(state); break;
    case 1: setLed1State(state); break;
    case 2: setLed2State(state); break;
    case 3: setLed3State(state); break;
    case 4: setLed4State(state); break;
    case 5: setLed5State(state); break;
    case 6: setLed6State(state); break;
    case 7: setLed7State(state); break;
    case 8: setLed8State(state); break;
  }
}

void setLed0State(bool state)
{
  SET_BIT_STATE(PORTD, 4, state);
}
void setLed1State(bool state)
{
  SET_BIT_STATE(PORTD, 5, state);
}
void setLed2State(bool state)
{
  SET_BIT_STATE(PORTD, 6, state);
}
void setLed3State(bool state)
{
  SET_BIT_STATE(PORTD, 7, state);
}
void setLed4State(bool state)
{
  SET_BIT_STATE(PORTB, 1, state);
}
void setLed5State(bool state)
{
  SET_BIT_STATE(PORTB, 0, state);
}
void setLed6State(bool state)
{
  SET_BIT_STATE(PORTB, 2, state);
}
void setLed7State(bool state)
{
  SET_BIT_STATE(PORTB, 3, state);
}
void setLed8State(bool state)
{
  SET_BIT_STATE(PORTB, 4, state);
}

// LED CONTROL FUNCTIONS
void turnOn()
{
  PORTD |= B11110000;
  PORTB |= B00011111;
}

void turnOff()
{
  PORTD &= B00001111;
  PORTB &= B11100000;
}

void display(int values)
{
  SET_BIT_STATE(PORTD, 4, (values >> 0 & 0x01));
  SET_BIT_STATE(PORTD, 5, (values >> 1 & 0x01));
  SET_BIT_STATE(PORTD, 6, (values >> 2 & 0x01));
  SET_BIT_STATE(PORTD, 7, (values >> 3 & 0x01));
  SET_BIT_STATE(PORTB, 1, (values >> 4 & 0x01));
  SET_BIT_STATE(PORTB, 0, (values >> 5 & 0x01));
  SET_BIT_STATE(PORTB, 2, (values >> 6 & 0x01));
  SET_BIT_STATE(PORTB, 3, (values >> 7 & 0x01));
  SET_BIT_STATE(PORTB, 4, (values >> 8 & 0x01));
}

void demoLed()
{
  turnOn();
  delay(300);
  turnOff();
  for(int i=0; i<ledNo; i++)
  {
    setLedState(i, LED_ON);
    delay(75);
    setLedState(i, LED_OFF);
  }

  for(int i=ledNo-1; i>=0; i--)
  {
    setLedState(i, LED_ON);
    delay(75);
    setLedState(i, LED_OFF);
  }
}