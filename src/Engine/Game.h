#pragma once


#include <Rendering\Renderer.h>
#include <Engine\Utils.h>
#include <Engine\GameMap\MapsManager.h>
#include <Rendering\FPSCounter.h>




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