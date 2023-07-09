#ifndef CONTSANTS_H
#define CONSTANTS_H

#include <Arduino.h>

static const short AUDIO_INPUT_PIN = A5;
static const short KEY_PIN = 2; 
static const float AUDIO_KEY_THRESHOLD = 100;
static const long  KEY_DEBOUNCE_MILLIS = 2000;
static const long  AUDIO_DEBOUNCE_MILLIS = 25;

#endif