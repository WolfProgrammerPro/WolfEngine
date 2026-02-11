#pragma once
#include <Board.h>


class Display
{
public:
    Display();
    void fillDisplayScreen(uint16_t color);
    void initDisplay();
    void fillDisplayRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
    void drawDisplayRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color);
    void setDisplayTextSize(size_t size);
    void setDisplayCursorPosition(uint16_t x, uint16_t y);
    void printText(const char * text);


private:
    Adafruit_ST7735 display;
};