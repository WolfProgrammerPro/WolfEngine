#include <Engine\Game.h>

Game game;

void setup()
{
    Serial.begin(115200);
    delay(2000);
    
    game.start();
}

void loop()
{
    game.loop();
}
