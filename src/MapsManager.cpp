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
    staticObjects[0][0] = GameObject(Vector2{10,7}, Vector2{1,1}, FINISH);
    staticObjectsLenghts[0] = 1;

    staticObjects[1][0] = GameObject(Vector2{15,8}, Vector2{1,1}, FINISH);
    staticObjects[1][1] = GameObject(Vector2{6,0}, Vector2{1,5}, WALL);
    staticObjects[1][2] = GameObject(Vector2{6,9}, Vector2{1,7}, WALL);
    staticObjectsLenghts[1] = 3;

    staticObjects[2][0] = GameObject(Vector2{15,8}, Vector2{1,1}, FINISH);
    staticObjects[2][1] = GameObject(Vector2{6,0}, Vector2{1,5}, WALL);
    staticObjects[2][2] = GameObject(Vector2{6,9}, Vector2{1,7}, WALL);
    staticObjects[2][3] = GameObject(Vector2{6,5}, Vector2{1,4}, DOOR, 1);
    staticObjects[2][4] = GameObject(Vector2{2,8}, Vector2{1,1}, KEY, 1);
    staticObjectsLenghts[2] = 5;

    staticObjects[3][0] = GameObject(Vector2{15,4}, Vector2{1,1}, FINISH);
    staticObjects[3][1] = GameObject(Vector2{5,0}, Vector2{1,8}, WALL);
    staticObjects[3][2] = GameObject(Vector2{5,10}, Vector2{1,6}, WALL);
    staticObjects[3][3] = GameObject(Vector2{2,5}, Vector2{1,1}, KEY, 1);
    staticObjects[3][4] = GameObject(Vector2{5,8}, Vector2{1,2}, DOOR, 1);
    staticObjects[3][5] = GameObject(Vector2{12,0}, Vector2{1,4}, WALL);
    staticObjects[3][6] = GameObject(Vector2{12,6}, Vector2{1,14}, WALL);
    staticObjects[3][7] = GameObject(Vector2{8,2}, Vector2{1,1}, KEY, 2);
    staticObjects[3][8] = GameObject(Vector2{12,4}, Vector2{1,2}, DOOR, 2);
    staticObjectsLenghts[3] = 9;

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
    }
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
    for (size_t i = 0; i < count; i++) {
        DinamicObject* obj = dinamicObjects[currentMap - 1][i];
        if (obj != nullptr && obj->isActive()) {
            renderer.renderObject(obj->getGameObject());
        }
    }
}

 void MapsManager::cleanupCurrentMapDinamicObjects() {
        size_t count = dinamicObjectsLenghts[currentMap - 1];
        for (size_t i = 0; i < count; i++) {
            delete dinamicObjects[currentMap - 1][i];
            dinamicObjects[currentMap - 1][i] = nullptr;
        }
        dinamicObjectsLenghts[currentMap - 1] = 0;
    }