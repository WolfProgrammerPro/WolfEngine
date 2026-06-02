#pragma once
#include <Engine\Utils.hpp>

class MovementDirector
{
private:
    Vector2 direction;
public:
    MovementDirector() {direction = vec2Zero;}
    MovementDirector(Vector2 movementDirection) {direction = movementDirection;}
    virtual Vector2 getDirection();
};