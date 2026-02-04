#include <MapsManager.h>

MapsManager::MapsManager()
{
    for (int i = 0; i < LEVEL_COUNT; i++)
    {
        maps_lengths[i] = 0;
    }
    loadMaps();
    
}


void MapsManager::init(Renderer& renderer)
{
    renderCurrentMap(renderer);
}

void MapsManager::nextMap(Renderer& renderer)
{
    if (currentMap + 1 <= LEVEL_COUNT)
    {
        currentMap++;
    }
    else
    {
        currentMap = 1;
        loadMaps();
    }
    renderCurrentMap(renderer);
}


void MapsManager::loadMaps()
{
    maps[0][0] = GameObject(Vector2{10,7}, Vector2{1,1},FINISH);
    maps_lengths[0] = 1;

    maps[1][0] = GameObject(Vector2{15,8}, Vector2{1,1},FINISH);
    maps[1][1] = GameObject(Vector2{6,0}, Vector2{1,5});
    maps[1][2] = GameObject(Vector2{6,9}, Vector2{1,7});
    maps_lengths[1] = 3;

    maps[2][0] = GameObject(Vector2{15,8}, Vector2{1,1},FINISH);
    maps[2][1] = GameObject(Vector2{6,0}, Vector2{1,5});
    maps[2][2] = GameObject(Vector2{6,9}, Vector2{1,7});
    maps[2][3] = GameObject(Vector2{6,5}, Vector2{1,4}, DOOR, 1);
    maps[2][4] = GameObject(Vector2{2,8}, Vector2{1,1}, KEY, 1);
    maps_lengths[2] = 5;

}

void MapsManager::renderCurrentMap(Renderer& renderer)
{
    renderer.setScreenColor(ST7735_BLACK);
    renderer.render(getCurrentMap(), maps_lengths[getCurrentMapNumber()-1]);
}