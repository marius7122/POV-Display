#include <Arduino.h>
#include <LedControl.h>


void setup() 
{
  ledInit();
  Serial.begin(9600);
}

bool arr[]  = {1, 0, 1, 0, 1, 0, 1, 0, 1};
bool arr2[] = {0, 1, 0, 1, 0, 1, 0, 1, 0};

void loop()
{
  display(arr);
  delayMicroseconds(100);
  display(arr2);
  delayMicroseconds(100);

}