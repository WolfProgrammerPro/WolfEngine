#include <GameObject.h>

void GameObject::setPosition(Vector2 pos)
{
    if (pos.x >= 0 && pos.x <= MAP_WIDTH - getSize().x && 
        pos.y >= 0 && pos.y <= MAP_HEIGHT - getSize().y)
    {
        setPositionValue(pos);
    }
}