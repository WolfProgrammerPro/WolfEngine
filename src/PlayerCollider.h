#pragma once

#include <ICollider.h>
#include <GameObject.h>
#include <Physics.h>
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
};