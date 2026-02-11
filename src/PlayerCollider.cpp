#include <PlayerCollider.h>
#include <GameManager.h>


PlayerCollider::PlayerCollider(GameObject& player) : gameObject(player)
{
    static GameManager* gameManager = new GameManager();
    this->gameManager = gameManager;
}

void PlayerCollider::checkCollisions(Renderer& renderer, MapsManager& mapsManager, IDinamicObjectMovement& objectMovement) {
    GameObject collision = physics.getCollision(mapsManager, gameObject);
    if (collision.isActive() && collision.getType() != NONE) {
        if (collision.getType() == KEY) {
            gameManager->removeAllObjectsWithId(mapsManager, collision.getId(), renderer);
        }
        if (collision.getType() == FINISH) {
            gameManager->finishLevel(mapsManager, renderer, objectMovement);
        }
    }
}

PlayerCollider::~PlayerCollider()
{
    gameManager = nullptr;
}