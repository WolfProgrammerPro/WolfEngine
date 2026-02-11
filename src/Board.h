#pragma once

#include <Adafruit_GFX.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   10
#define TFT_RST  8
#define TFT_DC   9

#define X_JOYSTICK_PIN A0
#define Y_JOYSTICK_PIN A1

unsigned long getMillis(void);

short getAnalogSygnal(uint8_t pin);

void initBoard(void);