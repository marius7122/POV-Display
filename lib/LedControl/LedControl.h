#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#define LED_ON  1
#define LED_OFF 0

const int ledPin[] = {4, 5, 6, 7, 9, 8, 10, 11, 12};
const int ledNo = 9;

void ledInit();                 // initialize
void display(int values);    // turn leds on and off acording to mask bits
void turnOn();                  // turn on all leds
void turnOff();                 // turn off all leds
void demoLed();                 // demo display

// turn on functions for all leds
void setLedState(int led, bool state);
void setLed0State(bool state);
void setLed1State(bool state);
void setLed2State(bool state);
void setLed3State(bool state);
void setLed4State(bool state);
void setLed5State(bool state);
void setLed6State(bool state);
void setLed7State(bool state);
void setLed8State(bool state);

#endif