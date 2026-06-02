#pragma once

#include <Engine\GameMap\MapsManager.hpp>

class MapsManagerRestarter
{
private:
    MapsManager* mapsManager;
public:
    void init(MapsManager& manager);
    void restart();
};