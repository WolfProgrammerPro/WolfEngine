#pragma once
#include <Hardware\Display.h>



class TextureDrawer
{
    public:
    void drawTexture(Display& display, const uint16_t* pixels, int screenPositionX, int screenPositionY, Vector2 textureSize);
};