#include <GameObjects\Movement\PlayerMovement.h>

Vector2 PlayerMovement::getMovementDirection()
{
    float x = 0;
    float y = 0;
    Vector2 joystickRotation = inputManager.getJoystickRotation();
    
    if (joystickRotation.x >= 1024 / 2 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        x = PLAYER_SPEED;
    }
    else if (joystickRotation.x <= 1024 / 2 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        x = -PLAYER_SPEED;
    }

    if (joystickRotation.y >= 1024 / 2 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        y = -PLAYER_SPEED;
    }
    else if (joystickRotation.y <= 1024 / 2 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
    {
        y = PLAYER_SPEED;
    }
    return Vector2{x,y};

}