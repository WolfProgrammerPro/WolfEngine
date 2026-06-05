#include <Engine\GameMap\MapLoader.hpp>

void MapLoader::load(GameObject* objects, int level)
{
    objectCreationCounter = 0;
    
    switch (level)
    {
    case 1:
        createPlayer(objects, Vector3{3,3,0});
        createWall(objects, Vector3{5,5,0}, Vector3{5, 1, 0});
        createKey(objects, Vector3{7,7,0}, 1);
        createDoor(objects, Vector3{9,9,0}, {1,3,0}, 1);
        createFinish(objects, Vector3{11, 3,0});
        break;
    
    default:
        createPlayer(objects, Vector3{3,3,0});
        createFinish(objects, Vector3{14, 3, 0});
        break;
    }
}

void MapLoader::createPlayer(GameObject* objects, Vector3 position)
{
    factory.createPlayer(objects, objectCreationCounter, position);
    objectCreationCounter++;
}

void MapLoader::createWall(GameObject* objects, Vector3 position, Vector3 size)
{
    factory.createWall(objects, objectCreationCounter, position, size);
    objectCreationCounter++;
}

void MapLoader::createKey(GameObject* objects, Vector3 position, int interactionIndex)
{
    factory.createKey(objects, objectCreationCounter, position, interactionIndex);
    objectCreationCounter++;
}

void MapLoader::createDoor(GameObject* objects, Vector3 position, Vector3 size, int interactionIndex)
{
    factory.createDoor(objects, objectCreationCounter, position, size, interactionIndex);
    objectCreationCounter++;
}

void MapLoader::createFinish(GameObject* objects, Vector3 position)
{
    factory.createFinish(objects, objectCreationCounter, position);
    objectCreationCounter++;
}