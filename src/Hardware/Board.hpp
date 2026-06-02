#pragma once

#include <Adafruit_GFX.h>
#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   15
#define TFT_RST  2
#define TFT_DC   4
#define TFT_MOSI 18
#define TFT_SCLK 23

#define X_JOYSTICK_PIN 34
#define Y_JOYSTICK_PIN 35

#define TFT_BL 16

unsigned long getMillis(void);

short getAnalogSygnal(uint8_t pin);

void initBoard(void);

void print(String text);