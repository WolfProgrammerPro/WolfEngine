#include <Engine\GameMap\MapsManager.hpp>

#include <Engine\GameMap\MapsManagerRestarter.hpp>

void MapsManager::init(MapsManagerRestarter& restarter)
{
    stats.init(restarter);
    loadMaps();
}

void MapsManager::loadMaps()
{
    for (int mapIndex = 0; mapIndex < LEVEL_COUNT; mapIndex++)
    {
        maps[mapIndex].load(loader, mapIndex+1);
    }
}

void MapsManager::update(Renderer& renderer)
{
    int currentLevel = stats.getCurrentLevel();
    if (currentLevel > 0 && currentLevel <= LEVEL_COUNT)
    {
        Map& map = maps[currentLevel-1];
        map.update(renderer, stats);
    }
}

void MapsManager::onGameRestarted()
{
    for (int mapIndex = 0; mapIndex < LEVEL_COUNT; mapIndex++)
    {
        maps[mapIndex].reset();
        maps[mapIndex].load(loader, mapIndex + 1);
    }
}
