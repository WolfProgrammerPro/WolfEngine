#include <GameObjects\Components\PlayerMovementDirector.hpp>

Vector2 PlayerMovementDirector::getDirection()
{
   Vector2 _direction = vec2Zero;
   Vector2 joystickRotation = input.getMovementJoystickRotation();
   if (joystickRotation.x >= 512 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
   {
    
    _direction.x = 1;
   }
   else
   {
        if (joystickRotation.x <= 512 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
        {
            _direction.x= -1;
        }
   }



   if (joystickRotation.y >= 512 + MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
   {
    _direction.y = -1;
   }
   else
   {
        if (joystickRotation.y <= 512 - MINIMAL_JOYSTICK_DEVIATION_TO_MOVE)
        {
            _direction.y= 1;
        }
   }
   return _direction;
}