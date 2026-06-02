#include <Engine\GameMap\MapsManagerRestarter.hpp>

void MapsManagerRestarter::init(MapsManager& manager)
{
    mapsManager = &manager;
}

void MapsManagerRestarter::restart()
{
    if (mapsManager != nullptr)
    {
        mapsManager->onGameRestarted();
    }
}