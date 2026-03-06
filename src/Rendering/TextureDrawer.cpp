#include <Rendering\TextureDrawer.h>

void TextureDrawer::drawTexture(Display& display, const uint16_t* pixels, int screenPositionX, int screenPositionY, Vector2 textureSize)
{
    if (pixels != nullptr)
    {
        int targetWidth = static_cast<int>(TEXTURE_DEFAULT_SIZE * textureSize.x);
        int targetHeight = static_cast<int>(TEXTURE_DEFAULT_SIZE * textureSize.y);

        int startX = max(0, screenPositionX);
        int startY = max(0, screenPositionY);
        int endX = min(REAL_WIDTH, screenPositionX + targetWidth);
        int endY = min(REAL_HEIGHT, screenPositionY + targetHeight);

        
        for (int y = startY; y < endY; y++)
        {
            for (int x = startX; x < endX; x++)
            {
                int textureX = x - screenPositionX;
                int textureY = y - screenPositionY;
                
                int pixelX = static_cast<int>(textureX / textureSize.x);
                int pixelY = static_cast<int>(textureY / textureSize.y);
                
                pixelX = min(pixelX, TEXTURE_DEFAULT_SIZE - 1);
                pixelY = min(pixelY, TEXTURE_DEFAULT_SIZE - 1);
                
                int pixelIndexInTexture = pixelY * TEXTURE_DEFAULT_SIZE + pixelX;
                
                if (pixelIndexInTexture >= TEXTURE_DEFAULT_SIZE * TEXTURE_DEFAULT_SIZE || pixelIndexInTexture < 0)
                {
                    pixelIndexInTexture = 0;
                }
                uint16_t pixelColor = pixels[pixelIndexInTexture];
                if (pixelColor != BACKGROUND_COLOR)
                {
                    display.drawPixel(x, y, pixelColor);
                }
            }
        }
    }
}