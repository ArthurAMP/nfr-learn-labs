//
// main.cpp
//
// Lab 2: Morse Code
// NFR Learn 2025
//
// Created by Evan Bertis-Sample
//

#include <Arduino.h>
#include <string>
#include "morse.hpp"

#define LED_PIN GPIO_NUM_32

enum DisplayMode
{
  STEP,
  SINUSOIDAL,
};

// Parameters that you can use to control the behavior of the program
struct MorseCodeParameters
{
  // The text to convert to Morse code
  const char *text = "SOS";
  // The time in milliseconds to wait between each Morse code character
  int dotDuration = 100;
  int dashDuration = 3 * dotDuration;
  // The time in milliseconds to wait between each Morse code character
  int interCharacterDelay = 2 * dotDuration;
  bool loop = true;
  int timeBetweenRepeats = 5 * dashDuration;
  DisplayMode displayMode = STEP;
};

MorseCodeParameters g_parameters;

// Function prototypes
int getMorseDuration(char c, const MorseCodeParameters &params);
void displayMorseCode(const MorseCodeParameters &params);
void displayCharacterSinusoidal(const char c, float t);
void displayCharacterStep(const char c);

void setup()
{
  // Setup the LED pin
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  switch (g_parameters.displayMode)
  {
  case STEP:
    digitalWrite(LED_PIN, LOW);
    break;
  case SINUSOIDAL:
    analogWrite(LED_PIN, 0);
    break;
  }

}

void loop()
{
  displayMorseCode(g_parameters);
  delay(g_parameters.timeBetweenRepeats);
}

void displayMorseCode(const MorseCodeParameters &params)
{
  std::string morse = textToMorse(params.text);
  Serial.println(morse.c_str());
  float t = 0; // between 0 and 1, marks the progress of the current character
  int timeUntilNextCharacter = 0;

  for (char c : morse)
  {
    int duration = getMorseDuration(c, params);
    int startTime = millis();
    int endTime = startTime + duration;
    float t = 0;
  
    while (millis() < endTime)
    {
      switch (params.displayMode)
      {
      case STEP:
        displayCharacterStep(c);
        break;
      case SINUSOIDAL:
        displayCharacterSinusoidal(c, t);
        break;
      }

      t = (millis() - startTime) / (float)duration;
      Serial.println(t);
    }

    switch (params.displayMode)
    {
    case STEP:
      digitalWrite(LED_PIN, LOW);
      break;
    case SINUSOIDAL:
      analogWrite(LED_PIN, 0);
      break;
    }
  }
}

int getMorseDuration(char c, const MorseCodeParameters &params)
{
  switch (c)
  {
  case '.':
    return params.dotDuration;
  case '-':
    return params.dashDuration;
  case ' ':
    return params.interCharacterDelay;
  default:
    return 0;
  }
}

void displayCharacterSinusoidal(const char c, float t)
{
  int brightness = 0;
  if (c == '.')
  {
    brightness = 255 * sin(2 * PI * t);
  }
  else if (c == '-')
  {
    brightness = 255 * sin(2 * PI * t);
  }
  else if (c == ' ')
  {
    brightness = 0;
  }
  analogWrite(LED_PIN, brightness);
}

void displayCharacterStep(const char c)
{
  Serial.println(c);
  digitalWrite(LED_PIN, HIGH);
}