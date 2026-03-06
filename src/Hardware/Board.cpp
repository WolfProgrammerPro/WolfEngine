#include <Hardware\Board.h>

unsigned long getMillis(void)
{
    return millis();
}

short getAnalogSygnal(uint8_t pin)
{
    return analogRead(pin);
}

void initBoard(void)
{
    analogReadResolution(10);
    analogSetWidth(10);
    analogSetAttenuation(ADC_11db);
    
    pinMode(TFT_CS, OUTPUT);
    pinMode(TFT_DC, OUTPUT);
    pinMode(TFT_RST, OUTPUT);
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);
    
    SPI.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
    
    digitalWrite(TFT_RST, LOW);
    delay(100);
    digitalWrite(TFT_RST, HIGH);
    delay(100);
    
}
