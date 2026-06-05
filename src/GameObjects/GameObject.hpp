#pragma once

#include <GameObjects\Components\Component.hpp>
#include <Engine\Utils.hpp>
#include <Hardware\Board.hpp>
#include <GameObjects\Components\Transform.hpp>
#include <GameObjects\Components\GraphicsComponent.hpp>
#include <Physics\Physics.hpp>
#include <GameObjects\Components\Movement.hpp>
#include <GameObjects\Components\Collider.hpp>
#include <GameObjects\Components\CollisionEventor.hpp>

class Map;


class GameObject
{
private:
    Movement movement;
    Transform transform;
    Physics physics;
    Collider collider;
    GraphicsComponent graphicsComponent;
    GameObjectType type;
    bool active = true;
    bool moving = false;
    bool colliding = true;
    unsigned long uniqueId;
    int interactionIndex;

public:
    static unsigned long nextId;
    GameObject() {type = NONE;}
    GameObject(Vector3 position, Vector3 size, GameObjectType objectType = NONE)
    {
        transform.setPosition(position);
        transform.setSize(size);
        uniqueId = nextId++;
        graphicsComponent.writeLastRenderedPosition(Vector3{-1, -1, -1});
        graphicsComponent.writeLastRenderedActive(false);
    }
    void setMovementDirection(MovementDirector& director);
    Vector3 getSize() {return transform.getSize();}
    Vector3 getPosition() {return transform.getPosition();}
    Vector3 getLastRenderedPosition() {return graphicsComponent.getLastRenderedPosition();}
    bool isActive() {return active;}
    bool getLastRenderedActive() {return graphicsComponent.getLastRenderedActive();}
    GameObjectType getType() {return type;}
    void writeLastRenderedPosition() {graphicsComponent.writeLastRenderedPosition(transform.getPosition());}
    void writeLastRenderedActive() {graphicsComponent.writeLastRenderedActive(active);}
    void setType(GameObjectType objectType) {type = objectType;}
    unsigned long getUniqueId() const {return uniqueId;}

    void update(Map& map, MapStats& stats);
    void reset()
    {
        type = NONE;
        active = true;
        moving = false;
        colliding = true;
        interactionIndex = 0;
        graphicsComponent.writeLastRenderedActive(false);
        graphicsComponent.writeLastRenderedPosition(Vector3{-1, -1, -1});
    }
    void setInteractionIndex(int index) {interactionIndex = index;}
    int getInteractionIndex() const {return interactionIndex;}
    bool isColliding() const {return colliding;}
    void offColliding() {colliding = false;}
    void setColliding(bool value) {colliding = value;}
    void setMovementSpeed(float newSpeed) {movement.setMovementSpeed(newSpeed);}
    void setMovementCooldown(unsigned long cooldown) {movement.setMovementCooldown(cooldown);}
    void setColliderEventor(CollisionEventor& eventor) {collider.setCollisionEventor(eventor);}
    void destroy() {active = false; }
    void setCleared(bool cleared) {graphicsComponent.setObjectCleared(cleared);}
    bool isCleared() const {return graphicsComponent.isCleared();}
    GameObject(const GameObject&) = delete;
    GameObject& operator=(const GameObject&) = delete;
};