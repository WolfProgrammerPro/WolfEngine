#include <Engine\GameMap\Map.hpp>

void Map::load(MapLoader& loader, int level)
{
    loader.load(objects, level);
    isFirstFrame = true;
    print("loaded");
}



void Map::update(Renderer& renderer, MapStats& stats)
{
    if (isFirstFrame)
    {
        Serial.println("First");
        renderer.setScreenColor(BACKGROUND_COLOR);
        isFirstFrame = false;
    }


    for (int objectIndex = 0; objectIndex < MAX_GAME_OBJECTS_PER_LEVEL; objectIndex++)
    {
        if (objects[objectIndex].getType() != NONE && objects[objectIndex].isActive())
        {
            objects[objectIndex].update(*this, stats);
        }
    }
    renderer.render(objects);
    
}

void Map::offAllObjectsWithInteractionId(int interactionId)
{
    for (int objectIndex = 0; objectIndex < MAX_GAME_OBJECTS_PER_LEVEL; objectIndex++)
    {
        if (objects[objectIndex].getInteractionIndex() == interactionId)
        {
            Serial.println("destroyed object with uniqueId: " + String(objects[objectIndex].getUniqueId()));
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
