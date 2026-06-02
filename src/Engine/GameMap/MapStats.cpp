#include <Engine\GameMap\MapStats.hpp>

#include <Engine\GameMap\MapsManagerRestarter.hpp>

void MapStats::nextLevel()
{
    if (mapsRestarter != nullptr)
    {
        if (currentLevel < LEVEL_COUNT)
        {
            currentLevel++;
        }
        else
        {
            currentLevel = 1;
            mapsRestarter->restart();
        }
    }
}

void MapStats::init(MapsManagerRestarter& restarter)
{
    mapsRestarter = &restarter;
}
