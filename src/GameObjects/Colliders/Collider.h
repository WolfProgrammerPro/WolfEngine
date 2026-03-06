#pragma once

#include <GameObjects\GameObject.h>
#include <Rendering\Renderer.h>
#include <GameObjects\Movement\DinamicObjectMovement.h>
#include <Physics\Physics.h>


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