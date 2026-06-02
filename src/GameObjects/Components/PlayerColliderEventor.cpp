#include <GameObjects\Components\PlayerColliderEventor.hpp>

#include <GameObjects\GameObject.hpp>
#include <Engine\GameMap\Map.hpp>


void PlayerColliderEventor::remoteEvent(GameObject& collission, Map& map, MapStats& stats)
{
    int interactionIndex = collission.getInteractionIndex();
    if (interactionIndex != 0)
    {
        map.offAllObjectsWithInteractionId(interactionIndex);
    }
    GameObjectType objectType = collission.getType();
    if (objectType == FINISH)
    {
        stats.nextLevel();
    }
}