#include <GameObjects\Components\Transform.hpp>

void Transform::setPosition(Vector2 newPosition)
{
    if (newPosition.x + size.x <= MAP_WIDTH && newPosition.x >= 0)
    {
        position.x = newPosition.x;
    }
    if (newPosition.y + size.y <= MAP_HEIGHT && newPosition.y >= 0)
    {
        position.y = newPosition.y;
    }
}