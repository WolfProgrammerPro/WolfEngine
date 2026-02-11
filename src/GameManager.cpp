#include <GameManager.h>

void GameManager::removeAllObjectsWithId(MapsManager& mapsManager, unsigned short id, Renderer& renderer)
{
    for (unsigned int i = 0; i < mapsManager.getStaticObjectsLenght(); i++)
    {
        GameObject& object = mapsManager.getStaticObjects()[i];
        if (object.getId() == id)
        {
            object.setActive(false);
            renderer.renderObject(object);
        }
    }
}

void GameManager::finishLevel(MapsManager& mapsManager, Renderer& renderer, IDinamicObjectMovement& objectMovement)  // ИЗМЕНИТЬ
{
    mapsManager.nextMap(renderer);
    objectMovement.resetPosition();
}