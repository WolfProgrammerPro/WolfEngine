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