#pragma once

#include <GameObjects\DinamicObject.h>
#include <GameObjects\Movement\MovingWallMovement.h>
#include <GameObjects\Movement\PlayerMovement.h>
#include <GameObjects\Colliders\PlayerCollider.h>

class ObjectFactory
{
    public:
    void createMovingWall(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts);
    void createDinamicObject(DinamicObject* object, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts);
    void createGameObject(Vector2 position, Vector2 size, GameObjectType type, unsigned short level, unsigned short id, GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* staticObjectsLenghts);
    void createFallingBlock(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts);
    DinamicObject* createPlayer();
};