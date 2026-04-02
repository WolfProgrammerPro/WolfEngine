#pragma once
#include <GameObjects\DinamicObject.h>
#include <GameObjects\Colliders\PlayerCollider.h>
#include <GameObjects\Movement\PlayerMovement.h>
#include <Rendering\Renderer.h>
#include <Engine\Utils.h>

class Player
{
public:
    Player() : gameObject(vec2Zero, vec2Zero, PLAYER), playerCollider(gameObject), playerMovement(gameObject) {};
    Player(Vector2 pos, Vector2 _size) : gameObject(pos, _size, PLAYER), playerCollider(gameObject), playerMovement(gameObject) {};
        
    void update(MapsManager& mapsManager, Renderer& renderer);
    GameObject& getGameObject()  {return gameObject;}
        
private:
    GameObject gameObject;
    PlayerCollider playerCollider;
    PlayerMovement playerMovement;
};