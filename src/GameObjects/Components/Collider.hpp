#pragma once
#include <Physics\Physics.hpp>
#include <GameObjects\Components\Transform.hpp>
#include <GameObjects\Components\CollisionEventor.hpp>
class Map;
class GameObject;

class Collider
{
private:
    CollisionEventor* eventor = nullptr;
public:
    bool canMoveToNewPosition(Physics& physics, Map& map, Transform& transform, Vector2 newPosition, unsigned long uniqueId);
    void update(Physics& physics, Map& map, Transform& transform, unsigned long uniqueId, MapStats& stats);
    void setCollisionEventor(CollisionEventor& newEventor) {eventor = &newEventor;}
};