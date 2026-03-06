#pragma once

#include <GameObjects\GameObject.h>
#include <Hardware\Board.h>

class MapsManager;
class DinamicObject;

class Physics
{
public:
    GameObject getCollision(MapsManager& mapsManager, const GameObject& object, unsigned short toucherUniqueId);
    bool hasLetToObjectMove(MapsManager& mapsManager, const Vector2& position, const Vector2& size, unsigned short objectId);
    
private:
    bool checkGameObjectOnCollision(const GameObject& obj1, const GameObject& obj2, unsigned short obj1UniqueId);
    const GameObject* checkGameObjectGroupOnCollision(const GameObject* objectGroup, size_t groupLength, const GameObject& toucher, unsigned short toucherUniqueId);
    const GameObject* checkDinamicObjectGroupOnCollision(DinamicObject** objectGroup, size_t groupLength, const GameObject& toucher, unsigned short toucherUniqueId);
};
