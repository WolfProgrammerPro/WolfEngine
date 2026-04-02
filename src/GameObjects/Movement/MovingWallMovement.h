#pragma once
#include <GameObjects\Movement\DinamicObjectMovement.h>

class MovingWallMovement : public DinamicObjectMovement
{
public:
    MovingWallMovement(GameObject& wall, Vector2 direction, float speed, int move_cooldown) : DinamicObjectMovement(wall, vec2Zero, move_cooldown, speed), movementDirection(direction) {}
protected:
    Vector2 getMovementDirection() override;
    Vector2 movementDirection;
};