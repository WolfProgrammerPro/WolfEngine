#include <Physics.h>
#include <MapsManager.h>
#include <DinamicObject.h>

GameObject Physics::getCollision(MapsManager& mapsManager, const GameObject& object)
{
    const GameObject* dinamicObjectCollider = checkDinamicObjectGroupOnCollision(
        mapsManager.getDinamicObjects(), 
        mapsManager.getDinamicObjectsLenght(), 
        object);
    
    if (dinamicObjectCollider != nullptr)
    {
        return *dinamicObjectCollider;
    }

    const GameObject* staticObjectCollider = checkGameObjectGroupOnCollision(
        mapsManager.getStaticObjects(),
        mapsManager.getStaticObjectsLenght(), 
        object);
    
    if (staticObjectCollider != nullptr)
    {
        return *staticObjectCollider;
    }

    return GameObject();
}

const GameObject* Physics::checkDinamicObjectGroupOnCollision(
    DinamicObject** objectGroup, 
    size_t groupLength, 
    const GameObject& toucher)
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
        
        if (checkGameObjectOnCollision(toucher, obj)) {
            return &obj;
        }
    }
    return nullptr;
}

const GameObject* Physics::checkGameObjectGroupOnCollision(
    const GameObject* objectGroup, 
    size_t groupLength, 
    const GameObject& toucher)
{
    if (objectGroup == nullptr) return nullptr;
    
    for (size_t i = 0; i < groupLength; i++)
    {
        if (!objectGroup[i].isActive() || objectGroup[i].getType() == NONE) {
            continue;
        }
        if (checkGameObjectOnCollision(toucher, objectGroup[i])) {
            return &objectGroup[i];
        }
    }
    return nullptr;
}

bool Physics::hasLetToObjectMove(MapsManager& mapsManager, const Vector2& position, const Vector2& size)
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
            if (checkGameObjectOnCollision(tempObject, obj)) {
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
            GameObjectType type = obj.getType();
            
            if (type == WALL || type == DOOR) {
                if (checkGameObjectOnCollision(tempObject, obj)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool Physics::checkGameObjectOnCollision(const GameObject& obj1, const GameObject& obj2)
{
    if (!obj2.isActive() || obj2.getType() == NONE || &obj2 == &obj1)
    {
        return false;
    }
    
    Vector2 pos1 = obj1.getPosition();
    Vector2 size1 = obj1.getSize();
    Vector2 pos2 = obj2.getPosition();
    Vector2 size2 = obj2.getSize();
    
    bool collisionInX = (pos1.x < pos2.x + size2.x) && (pos1.x + size1.x > pos2.x);
    bool collisionInY = (pos1.y < pos2.y + size2.y) && (pos1.y + size1.y > pos2.y);
    
    return collisionInX && collisionInY;
}