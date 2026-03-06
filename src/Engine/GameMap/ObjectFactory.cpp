#include <Engine\GameMap\ObjectFactory.h>

void ObjectFactory::createMovingWall(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts)
{
    DinamicObject* wall = new DinamicObject(position, size, WALL);
    MovingWallMovement* wallMovement = new MovingWallMovement(wall->getGameObject(), Vector2{-1, 0}, 0.25f ,300);
    wall->setMovement(wallMovement);
    createDinamicObject(wall, level, dinamicObjects, dinamicObjectsLenghts);
}

void ObjectFactory::createDinamicObject(DinamicObject* object, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts)
{
    if (level > 0 && level <= LEVEL_COUNT)
    {
        dinamicObjects[level-1][dinamicObjectsLenghts[level-1]] = object;
        dinamicObjectsLenghts[level-1]++;
    }
}

void ObjectFactory::createGameObject(Vector2 position, Vector2 size, GameObjectType type, unsigned short level, unsigned short id, GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* staticObjectsLenghts)
{
    if (level > 0 && level <= LEVEL_COUNT)
    {
        staticObjects[level-1][staticObjectsLenghts[level-1]] = GameObject(position, size, type, id);
        staticObjectsLenghts[level-1]++;
    }
}

void ObjectFactory::createFallingBlock(Vector2 position, Vector2 size, unsigned short level, DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL], size_t* dinamicObjectsLenghts)
{
    DinamicObject* wall = new DinamicObject(position, size, WALL);
    MovingWallMovement* wallMovement = new MovingWallMovement(wall->getGameObject(), Vector2{0, -1}, MINIMAL_STEP_ON_MAP ,PHYSICS_2D_FALL_DELAY);
    wall->setMovement(wallMovement);
    createDinamicObject(wall, level, dinamicObjects, dinamicObjectsLenghts);
}

DinamicObject* ObjectFactory::createPlayer()
{
    DinamicObject* player = new DinamicObject(
        Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}, 
        Vector2{PLAYER_SIZE_X, PLAYER_SIZE_Y}, 
        PLAYER
    );
    
    PlayerMovement* playerMovement = new PlayerMovement(player->getGameObject());
    player->setMovement(playerMovement);
    PlayerCollider* playerCollider = new PlayerCollider(player->getGameObject());
    player->setCollider(playerCollider);
    return player;
}