#include <Board.h>

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

}
