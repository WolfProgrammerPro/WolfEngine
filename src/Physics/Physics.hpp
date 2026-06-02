#pragma once


#include <Hardware\Board.hpp>
#include <Engine\Utils.hpp>


class Map;
class GameObject;
class Transform;


class Physics
{
public:
    GameObject* getCollision(Map& map, Transform& transform, unsigned short toucherUniqueId);
    bool hasLetToObjectMove(Map& map, Vector2 position, Vector2 size, unsigned short objectId);
    
private:
    bool checkGameObjectOnCollision(Transform& obj1 , GameObject& obj2, unsigned short obj1UniqueId);
    GameObject* checkGameObjectGroupOnCollision(GameObject* objectGroup, Transform& toucher, unsigned short toucherUniqueId);
};