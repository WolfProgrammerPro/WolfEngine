#pragma once

#include <GameObjects\Movement\DinamicObjectMovement.h>
#include <Engine\GameMap\MapsManager.h>
#include <Rendering\Renderer.h>

class GameManager
{
public:
    void removeAllObjectsWithId(MapsManager& mapsManager, unsigned short id, Renderer& renderer);
    void finishLevel(MapsManager& mapsManager, Renderer& renderer, IDinamicObjectMovement& objectMovement);
};