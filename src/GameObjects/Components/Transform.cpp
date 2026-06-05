#include <GameObjects\Components\Transform.hpp>

void Transform::setPosition(Vector3 newPosition)
{
    position.x = newPosition.x;
    position.y = newPosition.y;
    position.z = newPosition.z;
}

void Transform::setRotation(Vector3 newRotation)
{
    rotation.x = normalizeDegrees(newRotation.x);
    rotation.y = normalizeDegrees(newRotation.y);
    rotation.z = normalizeDegrees(newRotation.z);
}

float Transform::normalizeDegrees(float degrees)
{
    return 0;
}