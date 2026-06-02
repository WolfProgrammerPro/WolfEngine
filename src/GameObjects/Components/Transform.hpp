#pragma once
#include <Engine\Utils.hpp>


class Transform
{
private:
    Vector2 position;
    Vector2 size;

public:
    void setPosition(Vector2 newPosition);
    void setSize(Vector2 newSize) {size = newSize;}
    Vector2 getSize() {return size;}
    Vector2 getPosition() {return position;}
};