#include <PlayerCollider.h>

PlayerCollider::PlayerCollider(GameObject& player) : gameObject(player) {}

void PlayerCollider::checkCollisions(Renderer& renderer, MapsManager& mapsManager, IDinamicObjectMovement& objectMovement) {
    GameObject collision = physics.getCollision(mapsManager, gameObject);
    if (collision.isActive() && collision.getType() != NONE) {
        if (collision.getType() == KEY) {
            gameManager.removeAllObjectsWithId(mapsManager, collision.getId(), renderer);
        }
        if (collision.getType() == FINISH) {
            gameManager.finishLevel(mapsManager, renderer, objectMovement);
        }
    }
}