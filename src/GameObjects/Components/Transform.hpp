#pragma once
#include <Engine\Utils.hpp>


class Transform
{
private:
    Vector3 position;
    Vector3 rotation;
    Vector3 size;
    float normalizeDegrees(float degrees);

public:
    void setPosition(Vector3 newPosition);
    void setSize(Vector3 newSize) {size = newSize;}
    void setRotation(Vector3 newRotation);
    Vector3 getSize() {return size;}
    Vector3 getPosition() {return position;}
    Vector3 getRotation() {return rotation;}
};