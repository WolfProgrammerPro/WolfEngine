#pragma once

#include <GameObject.h>

class ICollider;
class IDinamicObjectMovement;
class MapsManager;
class Renderer;

class DinamicObject
{
public:
    DinamicObject();
    DinamicObject(const Vector2& pos, const Vector2& size, GameObjectType type = WALL);
    
    void update(MapsManager& mapsManager, Renderer& renderer);
    GameObject& getGameObject() { return gameObject; }
    const GameObject& getGameObject() const { return gameObject; }
    
    void setCollider(ICollider* collider) { this->collider = collider; }
    void setMovement(IDinamicObjectMovement* movement) { this->dinamicObjectMovement = movement; }
    
    bool isActive() const { return gameObject.isActive(); }
    void setActive(bool active) { gameObject.setActive(active); }
    
protected:
    GameObject gameObject;
    ICollider* collider;
    IDinamicObjectMovement* dinamicObjectMovement;
};