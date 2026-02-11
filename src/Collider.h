#pragma once

#include <GameObject.h>
#include <Renderer.h>
#include <DinamicObjectMovement.h>
#include <Physics.h>


class IGameManager;

class Collider
{
public:
    Collider(GameObject& object, IGameManager* _gameManager) : gameObject(object), gameManager(_gameManager) {};
    virtual void checkCollisions(Renderer& renderer, const GameObject*staticGameObjects, const GameObject* dinamicGameObjects, unsigned short staticObjectsCount, unsigned short dinamicObjectsCount, DinamicObjectMovement& objectMovement);
protected:
    GameObject& gameObject;
    Physics physics;
    IGameManager* gameManager;
};