#include <Engine\GameMap\Map.hpp>

void Map::load(MapLoader& loader, int level)
{
    loader.load(objects, level);
    isFirstFrame = true;
}



void Map::update(Renderer& renderer, MapStats& stats)
{
    if (isFirstFrame)
    {
        renderer.setScreenColor(BACKGROUND_COLOR);
        isFirstFrame = false;
    }
    renderer.render(objects);

    for (int objectIndex = 0; objectIndex < MAX_GAME_OBJECTS_PER_LEVEL; objectIndex++)
    {
        if (objects[objectIndex].getType() != NONE && objects[objectIndex].isActive())
        {
            objects[objectIndex].update(*this, stats);
        }
    }
    
    
    
}

void Map::offAllObjectsWithInteractionId(int interactionId)
{
    for (int objectIndex = 0; objectIndex < MAX_GAME_OBJECTS_PER_LEVEL; objectIndex++)
    {
        if (objects[objectIndex].getInteractionIndex() == interactionId)
        {
            objects[objectIndex].destroy();
        }
    }
}

void Map::reset()
{
    for (int i = 0; i < MAX_GAME_OBJECTS_PER_LEVEL; i++)
    {
        objects[i].reset();
    }
    isFirstFrame = true;
}
