#pragma once


#include <Renderer.h>
#include <GameObject.h>
#include <Player.h>
#include <Utils.h>
#include <InputManager.h>
#include <PlayerMovement.h>
#include <PlayerCollider.h>
#include <MapsManager.h>
#include <Arduino.h>
#include <FPSCounter.h>




class Game
{
public:
    Game();
    ~Game();
    void start();
    void loop();
private:
    Renderer renderer;
    Player player;
    MapsManager mapsManager;
    FPSCounter fpsCounter;
};