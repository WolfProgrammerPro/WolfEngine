#include <Hardware\Display.h>

Display::Display() : display(TFT_CS, TFT_DC, TFT_RST)
{
}

void Display::initDisplay()
{
    delay(500);
    display.initR(INITR_BLACKTAB);
    delay(100);
    
    display.setRotation(1);
    delay(100);
    
    display.fillScreen(BACKGROUND_COLOR);
}


void Display::fillDisplayScreen(uint16_t color)
{
    display.fillScreen(color);
}

void Display::fillDisplayRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
    display.fillRect(x, y, w, h, color);
}

void Display::drawDisplayRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t color)
{
    display.drawRect(x, y, w, h, color);
}

void Display::setDisplayTextSize(size_t size)
{
    display.setTextSize(size);
}

void Display::setDisplayCursorPosition(uint16_t x, uint16_t y)
{
    display.setCursor(x, y);
}

void Display::printText(const char * text)
{
    display.print(text);
}

void Display::drawPixel(uint16_t x, uint16_t y, uint16_t color)
{
    if (x >= 0 && x < REAL_WIDTH && y >= 0 && y < REAL_HEIGHT)
    {
        display.drawPixel(x, y, color);
    }
}