#include <MapsManager.h>
#include <DinamicObject.h>

MapsManager::MapsManager() : currentMap(1)
{
    for (int i = 0; i < LEVEL_COUNT; i++)
    {
        staticObjectsLenghts[i] = 0;
        dinamicObjectsLenghts[i] = 0;
    }
    
    for (int level = 0; level < LEVEL_COUNT; level++) {
        for (int obj = 0; obj < MAX_GAME_OBJECTS_PER_LEVEL; obj++) {
            dinamicObjects[level][obj] = nullptr;
        }
    }
    
    loadMaps();
}

MapsManager::~MapsManager()
{
    delete player;
    cleanupMaps();
}

void MapsManager::cleanupMaps()
{
    for (size_t level = 0; level < LEVEL_COUNT; level++) {
        for (size_t obj = 0; obj < dinamicObjectsLenghts[level]; obj++) {
            delete dinamicObjects[level][obj];
            dinamicObjects[level][obj] = nullptr;
        }
        dinamicObjectsLenghts[level] = 0;
    }
}

void MapsManager::loadMaps()
{

    createPlayer();
    createDinamicObject(player, 1);

    createGameObject(Vector2{10,7}, Vector2{1,1}, FINISH, 1);
    createMovingWall(Vector2{12,2}, Vector2{1,3}, 1);


    createGameObject(Vector2{15,8}, Vector2{1,1}, FINISH, 2);
    createGameObject(Vector2{6,0}, Vector2{1,5}, WALL, 2);
    createGameObject(Vector2{6,9}, Vector2{1,7}, WALL, 2);


    createGameObject(Vector2{15,8}, Vector2{1,1}, FINISH, 3);
    createGameObject(Vector2{6,0}, Vector2{1,5}, WALL, 3);
    createGameObject(Vector2{6,9}, Vector2{1,7}, WALL, 3);
    createGameObject(Vector2{6,5}, Vector2{1,4}, DOOR, 3, 1);
    createGameObject(Vector2{2,8}, Vector2{1,1}, KEY, 3, 1);

    createGameObject(Vector2{15,4}, Vector2{1,1}, FINISH, 4);
    createGameObject(Vector2{5,0}, Vector2{1,8}, WALL, 4);
    createGameObject(Vector2{5,10}, Vector2{1,6}, WALL, 4);
    createGameObject(Vector2{2,5}, Vector2{1,1}, KEY, 4, 1);
    createGameObject(Vector2{5,8}, Vector2{1,2}, DOOR, 4, 1);
    createGameObject(Vector2{12,0}, Vector2{1,4}, WALL, 4);
    createGameObject(Vector2{12,6}, Vector2{1,14}, WALL, 4);
    createGameObject(Vector2{8,2}, Vector2{1,1}, KEY, 4, 2);
    createGameObject(Vector2{12,4}, Vector2{1,2}, DOOR, 4, 2);

}

DinamicObject** MapsManager::getDinamicObjects()
{
    return dinamicObjects[currentMap - 1];
}

void MapsManager::init(Renderer& renderer)
{
    renderCurrentMap(renderer);
}

void MapsManager::nextMap(Renderer& renderer)
{
    cleanupCurrentMapDinamicObjects();
    if (currentMap < LEVEL_COUNT)
    {
        currentMap++;
    }
    else
    {
        currentMap = 1;
        loadMaps();
    }
    createPlayer();
    createDinamicObject(player, currentMap);
    renderCurrentMap(renderer);
    
}

void MapsManager::renderCurrentMap(Renderer& renderer)
{
    renderer.setScreenColor(COLOR_BLACK);
    renderStaticObjects(renderer);
    renderDinamicObjects(renderer);
}

void MapsManager::renderStaticObjects(Renderer& renderer)
{
    renderer.render(getStaticObjects(), staticObjectsLenghts[currentMap - 1]);
}

void MapsManager::renderDinamicObjects(Renderer& renderer)
{
    size_t count = dinamicObjectsLenghts[currentMap - 1];
    for (size_t i = 0; i < count; i++)
    {
        DinamicObject* obj = dinamicObjects[currentMap - 1][i];
        if (obj != nullptr && obj->isActive())
        {
            renderer.renderObject(obj->getGameObject());
        }
    }
}

void MapsManager::cleanupCurrentMapDinamicObjects()
{
    size_t count = dinamicObjectsLenghts[currentMap - 1];
    for (size_t i = 0; i < count; i++)
    {
        delete dinamicObjects[currentMap - 1][i];
        dinamicObjects[currentMap - 1][i] = nullptr;
    }
    dinamicObjectsLenghts[currentMap - 1] = 0;
    
}

void MapsManager::updateDinamicObjects(Renderer& renderer)
{
    for (size_t i = 0; i < getDinamicObjectsLenght(); i++)
    {
        DinamicObject* object = dinamicObjects[currentMap - 1][i];
        if (object != nullptr && object->isActive())
        {
            object->update(*this, renderer);
        }
    }
    renderDinamicObjects(renderer);
}



void MapsManager::createPlayer()
{
    if (player != nullptr) {
        player->getGameObject().setPosition(Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y});
        return;
    }

    player = new DinamicObject(
        Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}, 
        Vector2{PLAYER_SIZE_X, PLAYER_SIZE_Y}, 
        PLAYER
    );
    
    PlayerMovement* playerMovement = new PlayerMovement(player->getGameObject());
    player->setMovement(playerMovement);
    PlayerCollider* playerCollider = new PlayerCollider(player->getGameObject());
    player->setCollider(playerCollider);
}

void MapsManager::createMovingWall(Vector2 position, Vector2 size, unsigned short level)
{
    DinamicObject* wall = new DinamicObject(position, size, WALL);
    MovingWallMovement* wallMovement = new MovingWallMovement(wall->getGameObject());
    wall->setMovement(wallMovement);
    createDinamicObject(wall, level);
}

void MapsManager::createDinamicObject(DinamicObject* object, unsigned short level)
{
    if (level > 0 && level <= LEVEL_COUNT)
    {
        dinamicObjects[level-1][dinamicObjectsLenghts[level-1]] = object;
        dinamicObjectsLenghts[level-1]++;
    }
}

void MapsManager::createStaticObject(GameObject& object, unsigned short level)
{
    if (level > 0 && level <= LEVEL_COUNT)
    {
        staticObjects[level-1][staticObjectsLenghts[level-1]] = object;
        staticObjectsLenghts[level-1]++;
    }
    
}


void MapsManager::createGameObject(Vector2 position, Vector2 size, GameObjectType type, unsigned short level, unsigned short id)
{
    GameObject object = GameObject(position, size, type, id);
    createStaticObject(object, level);
}

