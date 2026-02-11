#pragma once
#include <GameObject.h>

class MapsManager;
class Renderer;
class DinamicObjectMovement;

class IGameManager {
public:
    virtual ~IGameManager() = default;
    virtual void removeAllObjectsWithId(MapsManager& mapsManager, unsigned short id, Renderer& renderer) = 0;
    virtual void finishLevel(MapsManager& mapsManager, Renderer& renderer, DinamicObjectMovement& objectMovement) = 0;
};