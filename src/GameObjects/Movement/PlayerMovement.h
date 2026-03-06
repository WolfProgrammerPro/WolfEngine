#pragma once

#include <GameObjects\Movement\DinamicObjectMovement.h>
#include <Hardware\InputManager.h>
#include <Engine\Utils.h>

class PlayerMovement : public DinamicObjectMovement
{
public:
    PlayerMovement(GameObject& player) 
        : DinamicObjectMovement(player, Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}, JOYSTICK_READ_MINIMAL_COOLDOWN, PLAYER_SPEED) {}
    
    
protected:
    Vector2 getMovementDirection() override;
    
private:
    InputManager inputManager;
};