#pragma once

#include <Engine\GameMap\ObjectFactory.h>

class MapsLoader
{
    public:
    void loadLevels(GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* staticObjectsLenghts,  size_t* dinamicObjectsLenghts); 
    private:
    ObjectFactory objectFactory;
    void createMovingWall(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts);
    void createDinamicObject(DinamicObject* object, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts);
    void createGameObject(Vector2 position, Vector2 size, GameObjectType type, unsigned short level, GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* staticObjectsLenghts, unsigned short id = 0);
    void createFallingBlock(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts);
};
