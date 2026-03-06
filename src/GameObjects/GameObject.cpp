#include <GameObjects\GameObject.h>

unsigned short GameObject::nextId = 1;


void GameObject::setPosition(Vector2 pos)
{
    if (isNewPositionValid(pos))
    {
        setPositionValue(pos);
    }
}

void GameObject::writeLastRenderedPosition() const
{
    lastRenderedPosition = position;
}

bool GameObject::isNewPositionValid(Vector2 pos)
{
    return (pos.x >= 0 && pos.x <= (float)MAP_WIDTH - getSize().x && pos.y >= 0 && pos.y <= (float)MAP_HEIGHT - getSize().y);
}

void GameObject::writeLastRenderedActive() const
{
    lastRenderedActive = active;
}

GameObject::~GameObject()
{

}

