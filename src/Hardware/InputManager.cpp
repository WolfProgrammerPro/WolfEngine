#include <Hardware\InputManager.hpp>

Vector2 InputManager::getMovementJoystickRotation()
{
    Vector2 rotation = vec2Zero;
    rotation.x = (float)getAnalogSygnal(X_JOYSTICK_PIN);
    rotation.y = (float)getAnalogSygnal(Y_JOYSTICK_PIN);
    return rotation;
}