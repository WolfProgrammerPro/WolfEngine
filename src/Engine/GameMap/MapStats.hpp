#pragma once
#include <Engine\Utils.hpp>

class MapsManagerRestarter;


class MapStats
{
private:
    int currentLevel = 1;
    MapsManagerRestarter* mapsRestarter;
public:
    void init(MapsManagerRestarter& restarter);
    int getCurrentLevel() {return currentLevel;}
    void nextLevel();
};