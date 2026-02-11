#include <DinamicObject.h>
#include <ICollider.h>
#include <IDinamicObjectMovement.h>
#include <MapsManager.h>
#include <Renderer.h>

DinamicObject::DinamicObject() 
    : gameObject(Vector2{0,0}, Vector2{0,0}, NONE)
    , collider(nullptr)
    , dinamicObjectMovement(nullptr) {}

DinamicObject::DinamicObject(const Vector2& pos, const Vector2& size, GameObjectType type): gameObject(pos, size, type), collider(nullptr), dinamicObjectMovement(nullptr)
{
    //Serial.begin(9600);
    //Serial.println("initialized");
}



void DinamicObject::update(MapsManager& mapsManager, Renderer& renderer)
{
    //Serial.println("updated");
    if (dinamicObjectMovement != nullptr) {
        dinamicObjectMovement->updatePosition(mapsManager);
    }
    if (collider != nullptr && dinamicObjectMovement != nullptr) {
        collider->checkCollisions(renderer, mapsManager, *dinamicObjectMovement);
    }
}