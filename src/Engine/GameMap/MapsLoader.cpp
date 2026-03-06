#include <Engine\GameMap\MapsLoader.h>
#include <Engine\Utils.h>

void MapsLoader::loadLevels(GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* staticObjectsLenghts,  size_t* dinamicObjectsLenghts)
{
    for (int level = 0; level < LEVEL_COUNT; level++)
    {
        staticObjectsLenghts[level] = 0;
        dinamicObjectsLenghts[level] = 0;
    }
    
    createGameObject(Vector2{10,7}, Vector2{2,2}, FINISH, 1, staticObjects, staticObjectsLenghts);

    createGameObject(Vector2{15,8}, Vector2{2,2}, FINISH, 2, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{6,0}, Vector2{1,5}, WALL, 2, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{6,9}, Vector2{1,7}, WALL, 2, staticObjects, staticObjectsLenghts);


    createGameObject(Vector2{15,8}, Vector2{2,2}, FINISH, 3, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{6,0}, Vector2{1,5}, WALL, 3, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{6,9}, Vector2{1,7}, WALL, 3, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{6,5}, Vector2{1,4}, DOOR, 3, staticObjects, staticObjectsLenghts, 1);
    createGameObject(Vector2{2,8}, Vector2{2,2}, KEY, 3, staticObjects, staticObjectsLenghts, 1);

    createGameObject(Vector2{15,4}, Vector2{2,2}, FINISH, 4, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{5,0}, Vector2{1,8}, WALL, 4, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{5,10}, Vector2{1,6}, WALL, 4, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{2,5}, Vector2{2,2}, KEY, 4, staticObjects, staticObjectsLenghts, 1);
    createGameObject(Vector2{5,8}, Vector2{1,2}, DOOR, 4, staticObjects, staticObjectsLenghts, 1);
    createGameObject(Vector2{12,0}, Vector2{1,4}, WALL, 4, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{12,6}, Vector2{1,14}, WALL, 4, staticObjects, staticObjectsLenghts);
    createGameObject(Vector2{8,2}, Vector2{2,2}, KEY, 4, staticObjects, staticObjectsLenghts, 2);
    createGameObject(Vector2{12,4}, Vector2{1,2}, DOOR, 4, staticObjects, staticObjectsLenghts, 2);
}

void MapsLoader::createMovingWall(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts)
{
    objectFactory.createMovingWall(position, size, level, dinamicObjects, dinamicObjectsLenghts);
}

void MapsLoader::createDinamicObject(DinamicObject* object, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts)
{
    objectFactory.createDinamicObject(object, level, dinamicObjects, dinamicObjectsLenghts);
}

void MapsLoader::createGameObject(Vector2 position, Vector2 size, GameObjectType type, unsigned short level, GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* staticObjectsLenghts, unsigned short id)
{
    objectFactory.createGameObject(position, size, type, level, id, staticObjects, staticObjectsLenghts);
}

void MapsLoader::createFallingBlock(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts)
{
    objectFactory.createFallingBlock(position, size, level, dinamicObjects, dinamicObjectsLenghts);
}