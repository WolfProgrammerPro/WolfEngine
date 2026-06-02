#pragma once

#include <GameObjects\Components\MovementDirector.hpp>
#include <Hardware\InputManager.hpp>

class PlayerMovementDirector : public MovementDirector
{
public:
    PlayerMovementDirector() : MovementDirector(vec2Zero) {};
    Vector2 getDirection() override;
    InputManager input;
};