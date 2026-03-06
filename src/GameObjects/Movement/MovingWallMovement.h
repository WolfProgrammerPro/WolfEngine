#pragma once
#include <GameObjects\Movement\DinamicObjectMovement.h>

class MovingWallMovement : public DinamicObjectMovement
{
public:
    MovingWallMovement(GameObject& wall, Vector2 direction, float speed, int move_cooldown) : DinamicObjectMovement(wall, Vector2{0, 0}, move_cooldown, speed), movementDirection(direction) {}
protected:
    Vector2 getMovementDirection() override;
private:
    Vector2 movementDirection;
};