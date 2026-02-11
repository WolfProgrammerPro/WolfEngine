#pragma once
#include <GameObject.h>

class IDinamicObjectMovement;
class ICollider;
class MapsManager;
class Renderer;


class IDinamicObject {
public:
    virtual ~IDinamicObject() = default;
    virtual GameObject& getGameObject() = 0;
    virtual void update(MapsManager& mapsManager, Renderer& renderer) = 0;
};