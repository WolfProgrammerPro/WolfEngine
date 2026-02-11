#include <Player.h>

void Player::update(MapsManager& mapsManager, Renderer& renderer)
{
    playerMovement.updatePosition(mapsManager);
    playerCollider.checkCollisions(renderer, mapsManager, playerMovement);
}