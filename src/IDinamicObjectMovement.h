#pragma once
#include <GameObject.h>
#include <Physics.h>

class MapsManager;

class IDinamicObjectMovement
{
public:
    virtual ~IDinamicObjectMovement() = default;
    virtual void updatePosition(MapsManager& mapsManager) = 0;
    virtual void resetPosition() = 0;
protected:
    virtual Vector2 getMovementDirection() = 0;
};