#pragma once

#include <DinamicObjectMovement.h>
#include <InputManager.h>
#include <Utils.h>

class PlayerMovement : public DinamicObjectMovement
{
public:
    PlayerMovement(GameObject& player) 
        : DinamicObjectMovement(
            player, 
            Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y},
            JOYSTICK_READ_MINIMAL_COOLDOWN
          ) {}
    
    
protected:
    Vector2 getMovementDirection() override;
    
private:
    InputManager inputManager;
};