#pragma once
#include <Engine\Utils.hpp>

class MovementDirector
{
private:
    Vector3 direction;
public:
    MovementDirector() {direction = vec3Zero;}
    MovementDirector(Vector3 movementDirection) {direction = movementDirection;}
    virtual Vector3 getDirection();
};