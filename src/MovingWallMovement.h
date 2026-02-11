#pragma once
#include <DinamicObjectMovement.h>

class MovingWallMovement : public DinamicObjectMovement
{
public:
    MovingWallMovement(GameObject& wall) 
        : DinamicObjectMovement(
            wall,
            Vector2{0, 0},
            JOYSTICK_READ_MINIMAL_COOLDOWN
          ) {}
    
protected:
    Vector2 getMovementDirection() override;
};