#pragma once
#include <GameObjects\Components\CollisionEventor.hpp>

class PlayerColliderEventor : public CollisionEventor
{
public:
    void remoteEvent(GameObject& collission, Map& map, MapStats& stats) override;
};