#pragma once

#include <DinamicObjectMovement.h>
#include <MapsManager.h>
#include <Renderer.h>

class GameManager
{
public:
    void removeAllObjectsWithId(MapsManager& mapsManager, unsigned short id, Renderer& renderer);
    void finishLevel(MapsManager& mapsManager, Renderer& renderer, IDinamicObjectMovement& objectMovement);
};