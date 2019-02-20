#include <Arduino.h>
#include <LedControl.h>
#include <models.h>

/*------------------DEFINES----------------------*/
#define HALL_SENSOR_PIN 2
#define ANGLES_PER_ROTATION 100
#define MEASURE_STUN 10000

/*--------------GLOBAL VARIABLES-----------------*/
volatile unsigned long timePerAngle = 1000000;
volatile unsigned long lastRotationTime = 0;
volatile unsigned long rotationDuration = 0;
volatile unsigned long timeFromLastRotation = 0;
volatile unsigned long currTime = 0;
int currAngle = 0;
int lastAngle = -1;
int startAngle = 90;

int img[ANGLES_PER_ROTATION];


/*---------------CUSTOM FUNCTIONS----------------*/
void rotationComplete()
{
  currTime = micros();

  // don't allow multiple detection in one rotation
  if(currTime - lastRotationTime < MEASURE_STUN)
    return;

  rotationDuration = currTime - lastRotationTime;
  timePerAngle = rotationDuration / ANGLES_PER_ROTATION;

  lastRotationTime = currTime;
}

void copyToImg(int from, bool fig[][ledNo], int len)
{
  int i, j;
  for(i = from; i < from + len; i++)
  {
    if(i >= ANGLES_PER_ROTATION)
      return;

    img[i] = 0;
    for(j = 0; j < ledNo; j++)
      if(fig[i][j])
        img[i] |= (1 << j);
  }
}

/*--------------ARDUINO FUNCTIONS----------------*/
void setup() 
{
  ledInit();
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_PIN), rotationComplete, FALLING);

  copyToImg(0, R, letterLen);

  demoLed();
}

void loop()
{
  currTime = micros();
  timeFromLastRotation = currTime - lastRotationTime;
  currAngle = timeFromLastRotation / timePerAngle;
  // currAngle += startAngle;
  currAngle %= ANGLES_PER_ROTATION;

  // led state must be updated
  if(currAngle != lastAngle)
  {
    display(img[currAngle]);
    lastAngle = currAngle;
  }

}