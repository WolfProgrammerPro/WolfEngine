#include <Physics\Physics.hpp>
#include <Engine\GameMap\Map.hpp>
#include <GameObjects\GameObject.hpp>

GameObject* Physics::getCollision(Map& map, Transform& transform, unsigned short toucherUniqueId)
{
    GameObject* collider = checkGameObjectGroupOnCollision(map.getObjects(), transform, toucherUniqueId);
    
    if (collider != nullptr)
    {
        return collider;
    }

    
    return nullptr;
}


GameObject* Physics::checkGameObjectGroupOnCollision(GameObject* objectGroup, Transform& toucher, unsigned short toucherUniqueId)
{
    if (objectGroup == nullptr) return nullptr;
    
    for (size_t i = 0; i < MAX_GAME_OBJECTS_PER_LEVEL; i++)
    {
        if (!objectGroup[i].isActive() || objectGroup[i].getType() == NONE) {
            continue;
        }
        if (checkGameObjectOnCollision(toucher, objectGroup[i], toucherUniqueId)) {
            return &objectGroup[i];
        }
    }
    return nullptr;
}

bool Physics::hasLetToObjectMove(Map& map, Vector3 position, Vector3 size, unsigned short objectId)
{
    for (size_t i = 0; i < MAX_GAME_OBJECTS_PER_LEVEL; i++)
    {
        GameObject& obj = map.getObjects()[i];
        if (!obj.isActive() || obj.getType() == NONE || obj.getUniqueId() == objectId || !obj.isColliding()) {
            continue;
        }
        
        Vector3 objPos = obj.getPosition();
        Vector3 objSize = obj.getSize();

        bool leftLess = position.x < objPos.x + objSize.x;
        bool rightGreater = position.x + size.x > objPos.x;
        bool collisionInX = leftLess && rightGreater;
    
        bool topLess = position.y < objPos.y + objSize.y;
        bool bottomGreater = position.y + size.y > objPos.y;
        bool collisionInY = topLess && bottomGreater;

    
        
        if (collisionInX && collisionInY) {
            return false;
        }
    }
    return true;
}

bool Physics::checkGameObjectOnCollision(Transform& obj1 , GameObject& obj2, unsigned short obj1UniqueId)
{
    if (!obj2.isActive() || obj2.getType() == NONE || obj2.getUniqueId() == obj1UniqueId)
    {
        return false;
    }
    
    Vector3 object1Position = obj1.getPosition();
    Vector3 object1Size = obj1.getSize();
    Vector3 object2Position = obj2.getPosition();
    Vector3 object2Size = obj2.getSize();
    
    bool leftLess = object1Position.x < object2Position.x + object2Size.x;
    bool rightGreater = object1Position.x + object1Size.x > object2Position.x;
    bool collisionInX = leftLess && rightGreater;
    
    bool topLess = object1Position.y < object2Position.y + object2Size.y;
    bool bottomGreater = object1Position.y + object1Size.y > object2Position.y;
    bool collisionInY = topLess && bottomGreater;

    
    return collisionInX && collisionInY;
    
}
