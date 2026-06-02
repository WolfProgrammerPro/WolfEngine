#pragma once
#include <Rendering\Renderer.hpp>
#include <GameObjects\GameObject.hpp>
#include <Engine\Utils.hpp>
#include <Engine\GameMap\MapLoader.hpp>
#include <Hardware\Board.hpp>
#include <Engine\GameMap\MapStats.hpp>



class Map
{
private:
    GameObject objects[MAX_GAME_OBJECTS_PER_LEVEL];
    int isFirstFrame = true;
public:
    void load(MapLoader& loader, int level);
    void update(Renderer& renderer, MapStats& stats);
    void reset();
    
    void offAllObjectsWithInteractionId(int interactionId);
    GameObject (&getObjects())[MAX_GAME_OBJECTS_PER_LEVEL] {
        return objects;
    }
};