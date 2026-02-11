#pragma once

#include <Utils.h>
#include <GameObject.h>
#include <Renderer.h>

class DinamicObject;

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
        size_t getStaticObjectsLenght() { return staticObjectsLenghts[currentMap - 1]; }
        size_t getDinamicObjectsLenght() { return dinamicObjectsLenghts[currentMap - 1]; }
        
    private:
        GameObject staticObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL];
        DinamicObject* dinamicObjects[LEVEL_COUNT][MAX_GAME_OBJECTS_PER_LEVEL];
        size_t staticObjectsLenghts[LEVEL_COUNT];
        size_t dinamicObjectsLenghts[LEVEL_COUNT];
        size_t currentMap;
        
        void loadMaps();
        void cleanupMaps();
        void cleanupCurrentMapDinamicObjects();
};