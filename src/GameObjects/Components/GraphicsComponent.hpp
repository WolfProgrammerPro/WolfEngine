#pragma once
#include <Engine\Utils.hpp>


class GraphicsComponent
{
private:
    Vector2 lastRenderedPosition;
    bool lastRenderedActive;
public:
    void writeLastRenderedPosition(Vector2 position) {lastRenderedPosition = position;}
    void writeLastRenderedActive(bool active) {lastRenderedActive = active;}
    Vector2 getLastRenderedPosition() {return lastRenderedPosition;}
    bool getLastRenderedActive() {return lastRenderedActive;}
};