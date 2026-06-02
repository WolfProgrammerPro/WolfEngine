#pragma once

#include <Hardware\Board.hpp>
#include <Rendering\Renderer.hpp>
#include <Engine\GameMap\MapsManager.hpp>
#include <Physics\Physics.hpp>
#include <Engine\GameMap\MapsManagerRestarter.hpp>

class Game
{
    public:
        void start();
        void update();
    private:
        Renderer renderer;
        MapsManager mapsManager;
        Physics physics;
        MapsManagerRestarter restarter;
};