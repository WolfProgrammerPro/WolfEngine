#pragma once
#include <Utils.h>

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
        mutable bool lastRenderedActive;
        Vector2 size;
        bool isNewPositionValid(Vector2 pos);
        mutable Vector2 lastRenderedPosition;
    public:
        GameObject() : position({-1,-1}), type(NONE), id(0), active(false), size({0,0}) {};
        GameObject(Vector2 pos, Vector2 _size, GameObjectType _type = WALL, unsigned short _id = 0) : position(pos), type(_type), id(_id), active(true), size(_size) {};
        #pragma GCC diagnostic pop
        Vector2 getPosition() const {return position;}
        Vector2 getLastRendererdPosition() const {return lastRenderedPosition;}
        Vector2 getSize() const {return size;}
        GameObjectType getType() const {return type;}
        bool isActive() const {return active;}
        bool getLastRenderedActive() const {return lastRenderedActive;}
        unsigned short getId() const {return id;}
        inline void setActive(bool newValue) {active = newValue;}
        void setPosition(Vector2 pos);
        void writeLastRenderedPosition() const;
        void writeLastRenderedActive() const;
    protected:
        void setPositionValue(Vector2 value) {position = value;}
};

