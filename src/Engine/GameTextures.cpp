#include <Engine\GameTextures.h>


const uint16_t* GameTextures::getTexturePixelsByObjectType(GameObjectType type)
{
    switch (type)
    {
        case PLAYER: return playerTexturePixels; break;
        case FINISH: return finishTexturePixels; break;
        case WALL: return wallTexturePixels; break;
        case KEY: return keyTexturePixels; break;
        case DOOR: return doorTexturePixels; break;
        default: return nullptr; break;
    }
}
