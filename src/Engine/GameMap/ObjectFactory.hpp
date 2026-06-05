#pragma once




#include <GameObjects\GameObject.hpp>
#include <GameObjects\Components\Movement.hpp>
#include <GameObjects\Components\PlayerMovementDirector.hpp>
#include <GameObjects\Components\PlayerColliderEventor.hpp>


class ObjectFactory
{
private:
    PlayerMovementDirector playerMovementDirector;
    PlayerColliderEventor playerColliderEventor;
    void createObject(GameObject* objects, int index, Vector3 position, Vector3 size);
public:
    void createPlayer(GameObject* objects, int index, Vector3 position);
    void createWall(GameObject* objects, int index, Vector3 position, Vector3 size);
    void createKey(GameObject* objects, int index, Vector3 position, int interactionIndex);
    void createDoor(GameObject* objects, int index, Vector3 position, Vector3 size, int interactionIndex);
    void createFinish(GameObject* objects, int index, Vector3 position);
};