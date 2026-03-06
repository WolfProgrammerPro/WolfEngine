#include <Engine\GameMap\MapsManager.h>

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
    mapsLoader.loadLevels(staticObjects, dinamicObjects, staticObjectsLenghts, dinamicObjectsLenghts);
    createPlayer();
}

MapsManager::~MapsManager()
{
    cleanupMaps();
    if (player != nullptr) {
        for (int level = 0; level < LEVEL_COUNT; level++) {
            for (size_t i = 0; i < dinamicObjectsLenghts[level]; i++) {
                if (dinamicObjects[level][i] == player) {
                    dinamicObjects[level][i] = nullptr;
                }
            }
        }
        delete player;
        player = nullptr;
    }
}

void MapsManager::cleanupMaps()
{
    for (size_t level = 0; level < LEVEL_COUNT; level++)
    {
        cleanupLevel(level);
    }
}

void MapsManager::cleanupLevel(int level)
{
    for (size_t i = 0; i < dinamicObjectsLenghts[level]; i++) {
        if (dinamicObjects[level][i] != nullptr) {
            DinamicObject* obj = dinamicObjects[level][i];
            if (obj == player) {
                dinamicObjects[level][i] = nullptr;
                continue;
            }
            
            obj->setMovement(nullptr);
            obj->setCollider(nullptr);
            delete obj;
            dinamicObjects[level][i] = nullptr;
        }
    }
    dinamicObjectsLenghts[level] = 0;
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
    renderer.setScreenColor(BACKGROUND_COLOR);
    int currentLevel = currentMap - 1;
    cleanupLevel(currentLevel);

    if (currentMap < LEVEL_COUNT)
    {
        currentMap++;
    }
    else
    {
        currentMap = 1;
        resetAllLevels();
    }

    if (player == nullptr)
    {
        createPlayer();
    }

    bool playerOnCurrentLevel = false;
    for (size_t i = 0; i < dinamicObjectsLenghts[currentMap - 1]; i++)
    {
        if (dinamicObjects[currentMap - 1][i] == player)
        {
            playerOnCurrentLevel = true;
            break;
        }
    }
    
    if (!playerOnCurrentLevel && player != nullptr)
    {
        if (dinamicObjectsLenghts[currentMap - 1] < MAX_GAME_OBJECTS_PER_LEVEL) {
            dinamicObjects[currentMap - 1][dinamicObjectsLenghts[currentMap - 1]] = player;
            dinamicObjectsLenghts[currentMap - 1]++;
        }
    }

    if (player != nullptr) {
        player->getGameObject().setPosition(Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y});
    }

    renderCurrentMap(renderer);
}

void MapsManager::resetAllLevels()
{
    DinamicObject* savedPlayer = player;

    cleanupMaps();
    mapsLoader.loadLevels(staticObjects, dinamicObjects, staticObjectsLenghts, dinamicObjectsLenghts);
    createPlayer();
}

void MapsManager::renderCurrentMap(Renderer& renderer)
{
    renderStaticObjects(renderer);
    renderDinamicObjects(renderer);
}

void MapsManager::renderStaticObjects(Renderer& renderer)
{
    size_t count = staticObjectsLenghts[currentMap - 1];
    
    for (size_t i = 0; i < count; i++)
    {
        GameObject& obj = staticObjects[currentMap - 1][i];
    }
    
    renderer.render(getStaticObjects(), count);
}

void MapsManager::renderDinamicObjects(Renderer& renderer)
{
    size_t count = dinamicObjectsLenghts[currentMap - 1];
    for (size_t i = 0; i < count; i++)
    {
        DinamicObject* obj = dinamicObjects[currentMap - 1][i];
        if (obj != nullptr && obj->isActive())
        {
            GameObject& gameObj = obj->getGameObject();
            renderer.renderObject(gameObj);
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
    player = objectFactory.createPlayer();
    
    if (player != nullptr) {
        int level = currentMap - 1;
        if (dinamicObjectsLenghts[level] < MAX_GAME_OBJECTS_PER_LEVEL)
         {
            dinamicObjects[level][dinamicObjectsLenghts[level]] = player;
            dinamicObjectsLenghts[level]++;
        } 
    }
}