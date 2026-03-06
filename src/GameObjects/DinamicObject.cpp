#include <GameObjects\DinamicObject.h>
#include <GameObjects\Colliders\ICollider.h>
#include <GameObjects\Movement\IDinamicObjectMovement.h>
#include <Engine\GameMap\MapsManager.h>
#include <Rendering\Renderer.h>

DinamicObject::DinamicObject() 
    : gameObject(Vector2{0,0}, Vector2{0,0}, NONE)
    , collider(nullptr)
    , dinamicObjectMovement(nullptr) {
    }

DinamicObject::DinamicObject(const Vector2& pos, const Vector2& size, GameObjectType type): gameObject(pos, size, type), collider(nullptr), dinamicObjectMovement(nullptr)
{
}

DinamicObject::~DinamicObject()
{
    if (collider != nullptr)
    {
        delete collider;
        collider = nullptr;
    }
    if (dinamicObjectMovement != nullptr)
    {
        delete dinamicObjectMovement;
        dinamicObjectMovement = nullptr;
    }
}



void DinamicObject::update(MapsManager& mapsManager, Renderer& renderer)
{
    if (dinamicObjectMovement != nullptr) {
        dinamicObjectMovement->updatePosition(mapsManager);
    }
    if (collider != nullptr && dinamicObjectMovement != nullptr) {
        collider->checkCollisions(renderer, mapsManager, *dinamicObjectMovement);
    }
}