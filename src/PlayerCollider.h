#pragma once

#include <ICollider.h>
#include <GameObject.h>
#include <Physics.h>
#include <GameManager.h>

class PlayerCollider : public ICollider {
public:
    PlayerCollider(GameObject& player);
    void checkCollisions(Renderer& renderer, MapsManager& mapsManager, IDinamicObjectMovement& objectMovement) override;

private:
    GameObject& gameObject;
    Physics physics;
    GameManager gameManager;
};