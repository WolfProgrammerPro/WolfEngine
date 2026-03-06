#pragma once

class Renderer;
class MapsManager;
class IDinamicObjectMovement;

class ICollider {
public:
    virtual ~ICollider() = default;
    virtual void checkCollisions(Renderer& renderer, MapsManager& mapsManager, IDinamicObjectMovement& objectMovement) = 0;
};