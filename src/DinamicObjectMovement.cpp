#include <DinamicObjectMovement.h>

DinamicObjectMovement::DinamicObjectMovement(GameObject& object, Vector2 positionOnReset, unsigned long cooldown) 
    : gameObject(object), starterPositionOnReset(positionOnReset), moveCooldown(cooldown) {}

void DinamicObjectMovement::updatePosition(MapsManager& mapsManager)
{
    if (getMillis() - lastMove >= moveCooldown)
    {
        lastMove = getMillis();
        Vector2 movementDirection = getMovementDirection();
        Vector2 newPosition = gameObject.getPosition() + movementDirection;
        moveTo(mapsManager, newPosition);
    }
}

void DinamicObjectMovement::moveTo(MapsManager& mapsManager, Vector2 position)
{
    if (!hasLetToObjectMove(mapsManager, position))
    {
        gameObject.setPosition(position);
    }
}

bool DinamicObjectMovement::hasLetToObjectMove(MapsManager& mapsManager, Vector2 newObjectPosition)
{
    return physics.hasLetToObjectMove(mapsManager, newObjectPosition, gameObject.getSize());
}

void DinamicObjectMovement::resetPosition()
{
    gameObject.setPosition(starterPositionOnReset);
}
