#pragma once
#include <GameObjects\Components\Component.hpp>
#include <GameObjects\Components\MovementDirector.hpp>
#include <Hardware\Board.hpp>
#include <GameObjects\Components\Transform.hpp>
#include <GameObjects\Components\Collider.hpp>

class Map;


class Movement
{
private:
    unsigned long moveCooldown;
    unsigned long lastMove;
    float movementSpeed;
    void move(Physics& physics, Transform& transform, Collider& collider, unsigned long uniqueId, Map& map);
    void moveTo(Physics& physics, Transform& transform, Collider& collider, unsigned long uniqueId, Map& map, Vector2 position);
public:
    MovementDirector* movementDirector;
    
    Movement()
    {
        moveCooldown = 0;
        movementSpeed = 0;
        lastMove = 0;
        movementDirector = nullptr;
    }
    
    Movement(float moveSpeed, unsigned long moveCd)
    {
        moveCooldown = moveCd;
        movementSpeed =  moveSpeed;
        movementDirector = nullptr; 
    }
    
    void setMovementSpeed(float speed)
    {
        movementSpeed = speed;
    }
    void setMovementCooldown(unsigned long cooldown)
    {
        moveCooldown = cooldown;
    }


    void setMovementDirector(MovementDirector& director) {
        movementDirector = &director;
    }
    void update(Physics& physics, Transform& transform, Collider& collider, unsigned long uniqueId, Map& map);
};