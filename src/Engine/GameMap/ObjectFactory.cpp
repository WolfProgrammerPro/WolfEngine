#include <Engine\GameMap\ObjectFactory.hpp>



void ObjectFactory::createPlayer(GameObject* objects, int index, Vector2 position)
{
    
    createObject(objects, index, position, Vector2{PLAYER_SIZE_X, PLAYER_SIZE_Y});
    objects[index].setType(PLAYER);
    objects[index].setMovementDirection(playerMovementDirector);
    objects[index].setColliderEventor(playerColliderEventor);
    objects[index].setMovementSpeed(PLAYER_SPEED);
    objects[index].setMovementCooldown(JOYSTICK_READ_MINIMAL_COOLDOWN);
}

void ObjectFactory::createWall(GameObject* objects, int index, Vector2 position, Vector2 size)
{
    createObject(objects, index, position, size);
    objects[index].setType(WALL);
}

void ObjectFactory::createKey(GameObject* objects, int index, Vector2 position, int interactionIndex)
{
    createObject(objects,index, position, Vector2{KEY_SIZE, KEY_SIZE});
    objects[index].setType(KEY);
    objects[index].setInteractionIndex(interactionIndex);
    objects[index].offColliding();
}

void ObjectFactory::createDoor(GameObject* objects, int index, Vector2 position, Vector2 size, int interactionIndex)
{
    createObject(objects, index, position, size);
    objects[index].setType(DOOR);
    objects[index].setInteractionIndex(interactionIndex);
}

void ObjectFactory::createObject(GameObject* objects, int index, Vector2 position, Vector2 size)
{
    objects[index].~GameObject();
    new(&objects[index]) GameObject(position, size);
}

void ObjectFactory::createFinish(GameObject* objects, int index, Vector2 position)
{
    createObject(objects, index, position, Vector2{1,1});
    objects[index].setType(FINISH);
    objects[index].offColliding();
}