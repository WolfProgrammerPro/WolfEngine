#pragma once

#include <Engine\Utils.hpp>
#include <Rendering\TexturesList.hpp>

class GameTextures
{
    public:
    const uint16_t* getTexturePixelsByObjectType(GameObjectType type);
};