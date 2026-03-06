#include <Physics\Physics.h>
#include <Engine\GameMap\MapsManager.h>
#include <GameObjects\DinamicObject.h>

GameObject Physics::getCollision(MapsManager& mapsManager, const GameObject& object, unsigned short toucherUniqueId)
{
    const GameObject* dinamicObjectCollider = checkDinamicObjectGroupOnCollision(mapsManager.getDinamicObjects(), mapsManager.getDinamicObjectsLenght(), object, toucherUniqueId);
    
    if (dinamicObjectCollider != nullptr)
    {
        return *dinamicObjectCollider;
    }

    const GameObject* staticObjectCollider = checkGameObjectGroupOnCollision(mapsManager.getStaticObjects(),mapsManager.getStaticObjectsLenght(), object, toucherUniqueId);
    
    if (staticObjectCollider != nullptr)
    {
        return *staticObjectCollider;
    }

    return GameObject();
}

const GameObject* Physics::checkDinamicObjectGroupOnCollision(DinamicObject** objectGroup, size_t groupLength, const GameObject& toucher, unsigned short toucherUniqueId)
{
    if (objectGroup == nullptr) return nullptr;
    
    for (size_t i = 0; i < groupLength; i++)
    {
        if (objectGroup[i] == nullptr || !objectGroup[i]->isActive()) {
            continue;
        }
        
        const GameObject& obj = objectGroup[i]->getGameObject();
        if (obj.getType() == NONE) {
            continue;
        }
        
        if (checkGameObjectOnCollision(toucher, obj, toucherUniqueId)) {
            return &obj;
        }
    }
    return nullptr;
}

const GameObject* Physics::checkGameObjectGroupOnCollision(const GameObject* objectGroup, size_t groupLength, const GameObject& toucher, unsigned short toucherUniqueId)
{
    if (objectGroup == nullptr) return nullptr;
    
    for (size_t i = 0; i < groupLength; i++)
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

bool Physics::hasLetToObjectMove(MapsManager& mapsManager, const Vector2& position, const Vector2& size,  unsigned short objectId)
{
    GameObject tempObject(position, size);
    for (size_t i = 0; i < mapsManager.getStaticObjectsLenght(); i++)
    {
        const GameObject& obj = mapsManager.getStaticObjects()[i];
        
        if (!obj.isActive()) {
            continue;
        }
        
        GameObjectType type = obj.getType();
        if (type == WALL || type == DOOR) {
            if (checkGameObjectOnCollision(tempObject, obj, objectId)) 
            {
                return true;
            }
        }
    }
    DinamicObject** dinamicObjects = mapsManager.getDinamicObjects();
    size_t dinamicCount = mapsManager.getDinamicObjectsLenght();
    
    if (dinamicObjects != nullptr) {
        for (size_t i = 0; i < dinamicCount; i++)
        {
            if (dinamicObjects[i] == nullptr || !dinamicObjects[i]->isActive()) {
                continue;
            }
            
            const GameObject& obj = dinamicObjects[i]->getGameObject();
            if (checkGameObjectOnCollision(tempObject, obj, objectId))
            {
                return true;
            }
        }
    }
    
    return false;
}

bool Physics::checkGameObjectOnCollision(const GameObject& obj1, const GameObject& obj2, unsigned short obj1UniqueId)
{
    if (!obj2.isActive() || obj2.getType() == NONE || &obj2 == &obj1 || obj2.getUniqueId() == obj1UniqueId)
    {
        return false;
    }
    Vector2 object1Position = obj1.getPosition();
    Vector2 object1Size = obj1.getSize();
    Vector2 object2Position = obj2.getPosition();
    Vector2 object2Size = obj2.getSize();
    
    bool leftLess = object1Position.x < object2Position.x + object2Size.x;
    bool rightGreater = object1Position.x + object1Size.x > object2Position.x;
    bool collisionInX = leftLess && rightGreater;
    
    bool topLess = object1Position.y< object2Position.y + object2Size.y;
    bool bottomGreater = object1Position.y + object1Size.y > object2Position.y;
    bool collisionInY = topLess && bottomGreater;

    
    return collisionInX && collisionInY;
}