#include <Engine\GameMap\MapLoader.hpp>

void MapLoader::load(GameObject* objects, int level)
{
    objectCreationCounter = 0;
    if (level == 1)
    {
        createPlayer(objects, Vector2{3,3});
        createWall(objects, Vector2{5,5}, Vector2{5, 1});
        createKey(objects, Vector2{7,7}, 1);
        createDoor(objects, Vector2{9,9}, {1,3}, 1);
        createFinish(objects, Vector2{11, 3});
    }
    else
    {
        createPlayer(objects, Vector2{3,3});
        createWall(objects, Vector2{15,4}, Vector2{1,3});
        createFinish(objects, Vector2{14, 3});
    }
}

void MapLoader::createPlayer(GameObject* objects, Vector2 position)
{
    factory.createPlayer(objects, objectCreationCounter, position);
    objectCreationCounter++;
}

void MapLoader::createWall(GameObject* objects, Vector2 position, Vector2 size)
{
    factory.createWall(objects, objectCreationCounter, position, size);
    objectCreationCounter++;
}

void MapLoader::createKey(GameObject* objects, Vector2 position, int interactionIndex)
{
    factory.createKey(objects, objectCreationCounter, position, interactionIndex);
    objectCreationCounter++;
}

void MapLoader::createDoor(GameObject* objects, Vector2 position, Vector2 size, int interactionIndex)
{
    factory.createDoor(objects, objectCreationCounter, position, size, interactionIndex);
    objectCreationCounter++;
}

void MapLoader::createFinish(GameObject* objects, Vector2 position)
{
    factory.createFinish(objects, objectCreationCounter, position);
    objectCreationCounter++;
}