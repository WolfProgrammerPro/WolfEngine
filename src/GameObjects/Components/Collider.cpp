#include <GameObjects\Components\Collider.hpp>
#include <Engine\GameMap\Map.hpp>
#include <GameObjects\GameObject.hpp>

bool Collider::canMoveToNewPosition(Physics& physics, Map& map, Transform& transform, Vector2 newPosition, unsigned long uniqueId)
{
    return physics.hasLetToObjectMove(map, newPosition, transform.getSize(), uniqueId);
}

void Collider::update(Physics& physics, Map& map, Transform& transform, unsigned long uniqueId, MapStats& stats)
{
    if (eventor != nullptr)
    {
        GameObject* collision = physics.getCollision(map, transform, uniqueId);
        if (collision != nullptr)
        {
            eventor->remoteEvent(*collision, map, stats);
        }
    }
}
