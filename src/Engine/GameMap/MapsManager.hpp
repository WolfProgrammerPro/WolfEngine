#pragma once

#include <Engine\GameMap\Map.hpp>
#include <Engine\Utils.hpp>
#include <Engine\GameMap\MapLoader.hpp>
#include <Engine\GameMap\MapStats.hpp>
#include <Rendering\Renderer.hpp>

class MapsManagerRestarter;


class MapsManager
{
private:
    Map maps[LEVEL_COUNT];
    MapLoader loader;
    MapStats stats;
    

    void loadMaps();
public:
    void init(MapsManagerRestarter& restarter);
    void update(Renderer& renderer);
    GameObject (&getObjects())[MAX_GAME_OBJECTS_PER_LEVEL] {
        return maps[stats.getCurrentLevel()-1].getObjects();
    }
    void onGameRestarted();
};