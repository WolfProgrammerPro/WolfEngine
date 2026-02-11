#pragma once

#include <Utils.h>
#include <GameObject.h>
#include <MovingWallMovement.h>
#include <Renderer.h>
//#include <Player.h>
#include <PlayerMovement.h>
#include <PlayerCollider.h>


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
        DinamicObject* player;
        void createPlayer();
        size_t staticObjectsLenghts[LEVEL_COUNT];
        size_t dinamicObjectsLenghts[LEVEL_COUNT];
        size_t currentMap;
        void loadMaps();
        void cleanupMaps();
        void cleanupCurrentMapDinamicObjects();
        void createMovingWall(Vector2 position, Vector2 size, unsigned short level);
        void createDinamicObject(DinamicObject* object, unsigned short level);
        void createStaticObject(GameObject& object, unsigned short level);
        void createGameObject(Vector2 position, Vector2 size, GameObjectType type, unsigned short level, unsigned short id = 0);
        
};