#pragma once


#include <Renderer.h>
#include <GameObject.h>
#include <Utils.h>
#include <InputManager.h>
#include <PlayerMovement.h>
#include <PlayerCollider.h>
#include <MapsManager.h>
#include <FPSCounter.h>




class Game
{
public:
    Game();
    void start();
    void loop();
private:
    Renderer renderer;
    MapsManager mapsManager;
    FPSCounter fpsCounter;
};