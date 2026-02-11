#pragma once

#include <GameObject.h>
#include <Board.h>

class MapsManager;
class DinamicObject;

class Physics
{
public:
    GameObject getCollision(MapsManager& mapsManager, const GameObject& object);
    bool hasLetToObjectMove(MapsManager& mapsManager, const Vector2& position, const Vector2& size);
    
private:
    bool checkGameObjectOnCollision(const GameObject& obj1, const GameObject& obj2);
    const GameObject* checkGameObjectGroupOnCollision(const GameObject* objectGroup, size_t groupLength, const GameObject& toucher);
    const GameObject* checkDinamicObjectGroupOnCollision(DinamicObject** objectGroup, size_t groupLength, const GameObject& toucher);
};
