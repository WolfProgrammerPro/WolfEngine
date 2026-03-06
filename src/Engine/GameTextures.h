#pragma once

#include <Engine\Utils.h>
#include <Rendering\TexturesList.h>

class GameTextures
{
    public:
    const uint16_t* getTexturePixelsByObjectType(GameObjectType type);
};