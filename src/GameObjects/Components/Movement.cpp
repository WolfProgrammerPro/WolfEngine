#include <GameObjects\Components\Movement.hpp>

void Movement::update(Physics& physics, Transform& transform, Collider& collider, unsigned long uniqueId, Map& map)
{
    move(physics, transform, collider, uniqueId, map);
}

void Movement::move(Physics& physics, Transform& transform, Collider& collider, unsigned long uniqueId, Map& map)
{
    if (movementDirector == nullptr) {
        Serial.println("ERROR: movementDirector is NULL in move()!");
        return;
    }

    if (getMillis() - lastMove >= moveCooldown)
    {
        lastMove = getMillis();
        Vector2 oldPosition = transform.getPosition();
        Vector2 newPosition = oldPosition + movementDirector->getDirection() * movementSpeed;
        if (newPosition != transform.getPosition())
        {
            moveTo(physics, transform, collider, uniqueId, map, newPosition);
        }
        
    }
}

void Movement::moveTo(Physics& physics, Transform& transform, Collider& collider, unsigned long uniqueId, Map& map, Vector2 position)
{

    if (collider.canMoveToNewPosition(physics, map, transform, position, uniqueId))
    {
        
        transform.setPosition(position);
    }
    else
    {
        print("cant move");
    }
}