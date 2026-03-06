#pragma once
#include <Engine\Utils.h>



class GameObject{
    private:
        Vector2 position;
        GameObjectType type;
        unsigned short id;
        unsigned short uniqueId;
        bool active;
        mutable bool lastRenderedActive;
        Vector2 size;
        
        mutable Vector2 lastRenderedPosition;

    public:
        static unsigned short nextId;
        GameObject() : position({-1,-1}), type(NONE), id(0), active(false), size({0,0}){};
        GameObject(Vector2 pos, Vector2 _size, GameObjectType _type = WALL, unsigned short _id = 0) : position(pos), type(_type), id(_id), active(true), size(_size),lastRenderedPosition(Vector2{-1,-1}), lastRenderedActive(false){ uniqueId = nextId++; };
        ~GameObject();
        #pragma GCC diagnostic pop

        Vector2 getPosition() const {return position;}
        Vector2 getLastRendererdPosition() const {return lastRenderedPosition;}
        Vector2 getSize() const {return size;}
        
        GameObjectType getType() const {return type;}
        bool isNewPositionValid(Vector2 pos);
        bool isActive() const {return active;}
        bool getLastRenderedActive() const {return lastRenderedActive;}
        unsigned short getId() const {return id;}
        unsigned short getUniqueId() const {return uniqueId;}
        inline void setActive(bool newValue) {active = newValue;}
        void setPosition(Vector2 pos);
        void writeLastRenderedPosition() const;
        void writeLastRenderedActive() const;
        
    protected:
        void setPositionValue(Vector2 value) {position = value;}
};

