#pragma once


class Physics;
class Transform;
class Collider;
class GameObject;

#include "Hardware\Board.hpp"

enum ComponentType
{
    None,
    ComponentMovement
};



class Component
{
public:
    virtual ~Component() = default;
    Component(ComponentType componentType) {type = componentType;}
    Component() {type = None;}
    ComponentType getType() {return type;}
    virtual void update(Physics& physics, Transform& transform, Collider& collider, unsigned long uniqueId, GameObject* objects);
private:
    ComponentType type;
};