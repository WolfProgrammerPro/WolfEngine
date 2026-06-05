#pragma once
#include <Engine\Utils.hpp>


class GraphicsComponent
{
private:
    Vector3 lastRenderedPosition;
    bool lastRenderedActive;
    bool objectCleared = false;
public:
    void writeLastRenderedPosition(Vector3 position) {lastRenderedPosition = position;}
    void writeLastRenderedActive(bool active) {lastRenderedActive = active;}
    void setObjectCleared(bool cleared) {objectCleared = cleared;}
    bool isCleared() const {return objectCleared;}
    Vector3 getLastRenderedPosition() {return lastRenderedPosition;}
    bool getLastRenderedActive() {return lastRenderedActive;}
};