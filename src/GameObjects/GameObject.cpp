#include <GameObjects\GameObject.hpp>

#include <GameObjects\Components\Collider.hpp>
#include <Engine\GameMap\Map.hpp>
#



unsigned long GameObject::nextId = 1;


void GameObject::update(Map& map, MapStats& stats)
{
    if (moving)
    {
        movement.update(physics, transform, collider, uniqueId, map);
    }
    collider.update(physics, map, transform, uniqueId, stats);
    
    
}
void GameObject::setMovementDirection(MovementDirector& director)
{
    movement.setMovementDirector(director);
    moving = true;
}