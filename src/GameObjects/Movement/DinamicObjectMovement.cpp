#include <GameObjects\Movement\DinamicObjectMovement.h>

DinamicObjectMovement::DinamicObjectMovement(GameObject& object, Vector2 positionOnReset, unsigned long cooldown, float speed) : gameObject(object), starterPositionOnReset(positionOnReset), moveCooldown(cooldown), movementSpeed(speed) {}

void DinamicObjectMovement::updatePosition(MapsManager& mapsManager)
{
    if (getMillis() - lastMove >= moveCooldown)
    {
        lastMove = getMillis();
        Vector2 movementDirection = getMovementDirection();
        Vector2 newPosition = gameObject.getPosition() + movementDirection;
        if (!gameObject.isNewPositionValid(newPosition))
        {
            newPosition = gameObject.getPosition() + Vector2{movementDirection.x, 0};
            if (!gameObject.isNewPositionValid(newPosition))
            {
                newPosition = gameObject.getPosition() + Vector2{0, movementDirection.y};
                if (!gameObject.isNewPositionValid(newPosition))
                {
                    newPosition = gameObject.getPosition();
                }
            }
        }
        moveTo(mapsManager, newPosition);
    }
}

void DinamicObjectMovement::moveTo(MapsManager& mapsManager, Vector2 position)
{
    if (position != gameObject.getPosition())
    {
        if (!hasLetToObjectMove(mapsManager, position))
        {
            gameObject.setPosition(position);
        }
    }
}




bool DinamicObjectMovement::hasLetToObjectMove(MapsManager& mapsManager, Vector2 newObjectPosition)
{
    return physics.hasLetToObjectMove(mapsManager, newObjectPosition, gameObject.getSize(), gameObject.getUniqueId());
}

void DinamicObjectMovement::resetPosition()
{
    gameObject.setPosition(starterPositionOnReset);
}
