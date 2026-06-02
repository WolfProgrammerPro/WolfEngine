#pragma once

#include <Engine\GameMap\MapStats.hpp>

class GameObject;
class Map;


class CollisionEventor
{
public:
    virtual void remoteEvent(GameObject& collission, Map& map, MapStats& stats);
};