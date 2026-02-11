#pragma once

#include <GameObject.h>
#include <Board.h>

class InputManager
{
    public:
        Vector2 getJoystickRotation() const 
        {
            return Vector2
            {
            getAnalogSygnal(X_JOYSTICK_PIN),
            getAnalogSygnal(Y_JOYSTICK_PIN)
            };
        }
};
