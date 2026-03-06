#pragma once

#include <GameObjects\GameObject.h>
#include <Hardware\Board.h>

class InputManager
{
    public:
        Vector2 getJoystickRotation() const 
        {
            return Vector2
            {
            (float)getAnalogSygnal(X_JOYSTICK_PIN),
            (float)getAnalogSygnal(Y_JOYSTICK_PIN)
            };
        }
};
