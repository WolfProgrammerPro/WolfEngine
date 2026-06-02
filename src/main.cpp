#include <Arduino.h>

#include <Engine\Game.hpp>

Game game;

void setup()
{
  game.start();
}

void loop() 
{
  game.update();
}
