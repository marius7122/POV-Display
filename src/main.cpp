#include <Arduino.h>
#include <LedControl.h>
#include <models.h>

/*------------------DEFINES----------------------*/
#define HALL_SENSOR_PIN 2
#define ANGLES_PER_ROTATION 128
#define MEASURE_STUN 10000
#define LETTER_SPACING 2
#define SPACE_LENGTH 4
#define MAX_WORDS 2

/*--------------GLOBAL VARIABLES-----------------*/
volatile unsigned long timePerAngle = 1000000;
volatile unsigned long lastRotationTime = 0;
volatile unsigned long rotationDuration = 0;
volatile unsigned long timeFromLastRotation = 0;
volatile unsigned long currTime = 0;
int currAngle = 0;
int lastAngle = -1;
int startAngle = 0;
// int wordDuration = 0;
// int currWord = 0;
// int wordNumber = 0;

int img[ANGLES_PER_ROTATION];
// String wordList[MAX_WORDS];

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

void clearImg()
{
  for(int i = 0; i < ANGLES_PER_ROTATION; i++)
    img[i] = 0;
}

void copyToImg(int from, int fig[], int len)
{
  int i;

  for(i = from; i < from + len; i++)
  {
    if(i >= ANGLES_PER_ROTATION)
      return;

    img[i] = fig[i-from];
  }
}

void loadText(String text)
{
  clearImg();

  int i, imgLen = 0, c, cLen;
  for(i=0;i<text.length();i++)
  {
    c = text[i];


    // letter or punctuation
    if(isAlpha(c) || c == '!')
    {
      c = toUpperCase(c);
      cLen = models::letterLen(c);

      switch(c)
      {
        case 'A': copyToImg(imgLen, models::A, cLen); break;
        case 'B': copyToImg(imgLen, models::B, cLen); break;
        case 'C': copyToImg(imgLen, models::C, cLen); break;
        case 'D': copyToImg(imgLen, models::D, cLen); break;
        case 'E': copyToImg(imgLen, models::E, cLen); break;
        case 'F': copyToImg(imgLen, models::F, cLen); break;
        case 'G': copyToImg(imgLen, models::G, cLen); break;
        case 'H': copyToImg(imgLen, models::H, cLen); break;
        case 'I': copyToImg(imgLen, models::I, cLen); break;
        case 'J': copyToImg(imgLen, models::J, cLen); break;
        case 'K': copyToImg(imgLen, models::K, cLen); break;
        case 'L': copyToImg(imgLen, models::L, cLen); break;
        case 'M': copyToImg(imgLen, models::M, cLen); break;
        case 'N': copyToImg(imgLen, models::N, cLen); break;
        case 'O': copyToImg(imgLen, models::O, cLen); break;
        case 'P': copyToImg(imgLen, models::P, cLen); break;
        case 'Q': copyToImg(imgLen, models::Q, cLen); break;
        case 'R': copyToImg(imgLen, models::R, cLen); break;
        case 'S': copyToImg(imgLen, models::S, cLen); break;
        case 'T': copyToImg(imgLen, models::T, cLen); break;
        case 'U': copyToImg(imgLen, models::U, cLen); break;
        case 'V': copyToImg(imgLen, models::V, cLen); break;
        case 'W': copyToImg(imgLen, models::W, cLen); break;
        case 'X': copyToImg(imgLen, models::X, cLen); break;
        case 'Y': copyToImg(imgLen, models::Y, cLen); break;
        case 'Z': copyToImg(imgLen, models::Z, cLen); break;
        case '!': copyToImg(imgLen, models::Exclamation_Mark, cLen); break;
      }

      imgLen += cLen;
    }

    // special character
    if(c == '/')
    {
      String s = "";

      i++;
      while(text[i] != '/' && i < text.length())
        s += text[i++];

      
      int sLen = 0;
      if(s == "heart")
      {
        sLen = 10;
        copyToImg(imgLen, models::Heart, sLen);
      }

      if(s == "smiley")
      {
        sLen = 8;
        copyToImg(imgLen, models::Smiley, sLen);
      }

      imgLen += sLen;
    }

    
    if(i != text.length() - 1)
    {
      imgLen += LETTER_SPACING;
      if(c == ' ')
        imgLen += SPACE_LENGTH;
    }
  }

  if(imgLen > ANGLES_PER_ROTATION)
    imgLen = ANGLES_PER_ROTATION;

  // center image
  startAngle = ANGLES_PER_ROTATION - imgLen / 2;
}

void processCommand(String s)
{
  // wordDuration = 0;
  // s.toUpperCase();

  Serial.println("S = ");
  Serial.println(s);

  // blink mode (change words every x seconds, x is specified after \blink)
  /*if(s.startsWith("\\blink"))
  {
    Serial.println("/blink/");
    wordDuration = s[6] - '0';
    currWord = 0;

    // split words
    int i;
    int wordIndex = 0;
    String aux = "";
    for(i = 8; i < s.length(); i++)
    {
      if(s[i] >= 'A' && s[i] <= 'Z')
        aux += s[i];
      else
      {
        wordList[wordIndex++] = aux;
        Serial.println(aux);
        aux = "";
        if(wordIndex == MAX_WORDS)
          break;
      }
    }
  }*/

  // normal mode (just display text)
  // else
    loadText(s);
}

/*--------------ARDUINO FUNCTIONS----------------*/
void setup() 
{
  Serial.begin(9600);

  ledInit();
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_PIN), rotationComplete, FALLING);


  Serial.println("Start processing");
  processCommand("hello");


  demoLed();
}

void loop()
{
  currTime = micros();
  timeFromLastRotation = currTime - lastRotationTime;
  currAngle = timeFromLastRotation / timePerAngle;
  currAngle += startAngle;
  currAngle %= ANGLES_PER_ROTATION;
  currAngle = ANGLES_PER_ROTATION - 1 - currAngle;

  // led state must be updated
  if(currAngle != lastAngle)
  {
    display(img[currAngle]);
    lastAngle = currAngle;
  }

  if(Serial.available() > 0)
  {
    String command = Serial.readString();

    processCommand(command);
  }
}