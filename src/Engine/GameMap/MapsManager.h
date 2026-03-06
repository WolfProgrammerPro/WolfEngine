#pragma once

#include <Engine\Utils.h>
#include <GameObjects\GameObject.h>
#include <Rendering\Renderer.h>
#include <Engine\GameMap\MapsLoader.h>
#include <Engine\GameMap\ObjectFactory.h>


class DinamicObject;
class Player;

class MapsManager
{
    public:
        MapsManager();
        ~MapsManager();
        
        void nextMap(Renderer& renderer);
        void init(Renderer& renderer);
        GameObject* getStaticObjects() { return staticObjects[currentMap - 1]; }
        DinamicObject** getDinamicObjects();
        
        size_t getCurrentMapNumber() { return currentMap; }
        void renderCurrentMap(Renderer& renderer);
        void renderStaticObjects(Renderer& renderer);
        void renderDinamicObjects(Renderer& renderer);
        void updateDinamicObjects(Renderer& renderer);
        size_t getStaticObjectsLenght() { return staticObjectsLenghts[currentMap - 1]; }
        size_t getDinamicObjectsLenght() { return dinamicObjectsLenghts[currentMap - 1]; }
        DinamicObject* getCurrentPlayer() { return dinamicObjects[currentMap - 1][0]; }

        
    private:
        GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL];
        DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL];
        DinamicObject* player = nullptr;
        MapsLoader mapsLoader;
        ObjectFactory objectFactory;
        void createPlayer();
        size_t staticObjectsLenghts[LEVEL_COUNT];
        size_t dinamicObjectsLenghts[LEVEL_COUNT];
        size_t currentMap;
        void cleanupMaps();
        void resetAllLevels();
        void cleanupLevel(int level);
        void cleanupCurrentMapDinamicObjects();
};