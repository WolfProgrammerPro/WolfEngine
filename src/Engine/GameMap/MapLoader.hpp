#pragma once
#include <Engine\GameMap\ObjectFactory.hpp>
#include <Hardware\Board.hpp>

class MapLoader
{
private:
    ObjectFactory factory;
    void createPlayer(GameObject* objects, Vector3 position);
    void createWall(GameObject* objects, Vector3 position, Vector3 size);
    void createKey(GameObject* objects, Vector3 position, int interactionIndex);
    void createDoor(GameObject* objects, Vector3 position, Vector3 size, int interactionIndex);
    void createFinish(GameObject* objects, Vector3 position);
    int objectCreationCounter = 0;
public:
    void load(GameObject* objects, int level);
};