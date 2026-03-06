#pragma once

#include <Adafruit_GFX.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_RST  4
#define TFT_DC   15
#define TFT_MOSI 23
#define TFT_SCLK 18

#define X_JOYSTICK_PIN 34
#define Y_JOYSTICK_PIN 35

#define TFT_BL 16

unsigned long getMillis(void);

short getAnalogSygnal(uint8_t pin);

void initBoard(void);