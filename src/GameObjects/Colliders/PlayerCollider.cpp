#include <GameObjects\Colliders\PlayerCollider.h>
#include <Engine\GameManager.h>

GameManager* PlayerCollider::getGameManager()
{
    static GameManager instance;
    return &instance;
}


PlayerCollider::PlayerCollider(GameObject& player) : gameObject(player)
{
    gameManager = getGameManager();
}

void PlayerCollider::checkCollisions(Renderer& renderer, MapsManager& mapsManager, IDinamicObjectMovement& objectMovement) 
{
    if (gameManager == nullptr) {
        return;
    }
    
    GameObject collision = physics.getCollision(mapsManager, gameObject, gameObject.getUniqueId());
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