#include <PlayerMovement.h>

Vector2 PlayerMovement::getMovementDirection()
{
    short x = 0;
    short y = 0;
    Vector2 joystickRotation = inputManager.getJoystickRotation();
    
    
    if (joystickRotation.x >= 1024 / 2 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        x = 1;
    }
    else if (joystickRotation.x <= 1024 / 2 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        x = -1;
    }

    if (joystickRotation.y >= 1024 / 2 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        y = -1;
    }
    else if (joystickRotation.y <= 1024 / 2 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        y = 1;
    }

    
    return Vector2{x,y};

}

void PlayerMovement::updatePosition(MapsManager& mapsManager)
{
    if (getMillis() - lastMove >= moveCooldown)
    {
        lastMove = getMillis();
        Vector2 movementDirection = getMovementDirection();
        Vector2 newPosition = gameObject.getPosition() + movementDirection;
        if (!physics.hasLetToObjectMove(mapsManager, newPosition, gameObject.getSize()))
        {
            gameObject.setPosition(newPosition);
        }
    }
}

void PlayerMovement::resetPosition()
{
    gameObject.setPosition(starterPositionOnReset);
    lastMove = 0;
}