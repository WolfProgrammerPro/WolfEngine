#pragma once

#include <GameObjects\Components\MovementDirector.hpp>
#include <Hardware\InputManager.hpp>

class PlayerMovementDirector : public MovementDirector
{
public:
    PlayerMovementDirector() : MovementDirector(vec3Zero) {};
    Vector3 getDirection() override;
    InputManager input;
};