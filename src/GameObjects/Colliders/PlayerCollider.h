#pragma once

#include <GameObjects\Colliders\ICollider.h>
#include <GameObjects\GameObject.h>
#include <Physics\Physics.h>

class GameManager; 

class PlayerCollider : public ICollider {
public:
    PlayerCollider(GameObject& player);
    ~PlayerCollider();
    void checkCollisions(Renderer& renderer, MapsManager& mapsManager, IDinamicObjectMovement& objectMovement) override;

private:
    GameObject& gameObject;
    Physics physics;
    GameManager* gameManager;

    static GameManager* getGameManager();
};