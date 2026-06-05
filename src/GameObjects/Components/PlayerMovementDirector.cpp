#include <GameObjects\Components\PlayerMovementDirector.hpp>

Vector3 PlayerMovementDirector::getDirection()
{
   Vector3 _direction = vec3Zero;
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