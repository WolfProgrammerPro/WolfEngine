#pragma once
#include <Engine\GameMap\ObjectFactory.hpp>
#include <Hardware\Board.hpp>

class MapLoader
{
private:
    ObjectFactory factory;
    void createPlayer(GameObject* objects, Vector2 position);
    void createWall(GameObject* objects, Vector2 position, Vector2 size);
    void createKey(GameObject* objects, Vector2 position, int interactionIndex);
    void createDoor(GameObject* objects, Vector2 position, Vector2 size, int interactionIndex);
    void createFinish(GameObject* objects, Vector2 position);
    int objectCreationCounter = 0;
public:
    void load(GameObject* objects, int level);
};