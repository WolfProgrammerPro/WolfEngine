#pragma once

#include <Arduino.h>

enum GameObjectType
{
    NONE,
    WALL,
    PLAYER,
    KEY,
    DOOR,
    FINISH
};


struct Vector2
{
    short x;
    short y;
    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2& other) const {
        return x != other.x || y != other.y;
    }
    Vector2 operator+(const Vector2& other) const {
        Vector2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
};


class GameObject{
    private:
        Vector2 position;
        GameObjectType type;
        unsigned short id;
        bool active;
        Vector2 size;
    public:
        GameObject() : position({0,0}), type(NONE), id(0), active(false), size({0,0}) {};
        GameObject(Vector2 pos, Vector2 _size, GameObjectType _type = WALL, unsigned short _id = 0) : position(pos), type(_type), id(_id), active(true), size(_size) {};
        #pragma GCC diagnostic pop
        Vector2 getPosition() const {return position;}
        Vector2 getSize() const {return size;}
        GameObjectType getType() const {return type;}
        bool isActive() const {return active;}
        unsigned short getId() const {return id;}
        inline void setActive(bool newValue) {active = newValue;}

    protected:
        void setPositionValue(Vector2 value) {position = value;}
        
};

