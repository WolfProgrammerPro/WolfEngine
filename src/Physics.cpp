#include <Physics.h>



GameObject Physics::getCollision(MapsManager& mapsManager, GameObject& object)
{
    Vector2 objectPosition = object.getPosition();
    Vector2 objectSize = object.getSize();
    
    for (unsigned int i = 0; i < mapsManager.getCurrentMapSize(); i++)
    {
        GameObject& checkingObject = mapsManager.getCurrentMap()[i];
        if (!checkingObject.isActive() || checkingObject.getType() == NONE || &checkingObject == &object) {
            continue;
        }
        
        Vector2 checkingObjectPosition = checkingObject.getPosition();
        Vector2 checkingObjectSize = checkingObject.getSize();
        
        bool collisionInX = (objectPosition.x < checkingObjectPosition.x + checkingObjectSize.x) && (objectPosition.x + objectSize.x > checkingObjectPosition.x);
        bool collisionInY = (objectPosition.y < checkingObjectPosition.y + checkingObjectSize.y) && (objectPosition.y + objectSize.y > checkingObjectPosition.y);
        
        if (collisionInX && collisionInY)
        {
            return checkingObject;
        }
    }
    
    return GameObject();
}

bool Physics::hasLetToObjectMove(MapsManager& mapsManager, Vector2 position, Vector2 size)
{
    GameObject object = GameObject(position, size);

    for (unsigned int i = 0; i < mapsManager.getCurrentMapSize(); i++)
    {
        GameObject collision = getCollision(mapsManager, object);
        if (collision.getType() != NONE && collision.getType() != KEY && collision.getType() != FINISH)
        {
            return true;
        }
    }
    return false;
}