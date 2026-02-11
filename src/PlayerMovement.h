#pragma once

#include <IDinamicObjectMovement.h>
#include <InputManager.h>
#include <Utils.h>

class PlayerMovement : public IDinamicObjectMovement
{
public:
    PlayerMovement(GameObject& player) 
        : gameObject(player), 
          starterPositionOnReset(Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}), 
          moveCooldown(JOYSTICK_READ_MINIMAL_COOLDOWN) {}
    
    void updatePosition(MapsManager& mapsManager) override;
    void resetPosition() override;
    
protected:
    Vector2 getMovementDirection() override;
    
private:
    GameObject& gameObject;
    Physics physics;
    Vector2 starterPositionOnReset;
    unsigned long lastMove = 0;
    unsigned long moveCooldown;
    InputManager inputManager;
};