#include <Rendering\Renderer.hpp>

Renderer::Renderer() {}


void Renderer::setScreenColor(uint16_t color)
{
    display.fillDisplayScreen(color);
}




void Renderer::render(GameObject* gameObjects)
{
    for (size_t i = 0; i < MAX_GAME_OBJECTS_PER_LEVEL; i++)
    {
        GameObject& object = gameObjects[i];
        renderObject(object);
    }
}



void Renderer::renderObject(GameObject& gameObject)
{
    if (needRenderObject(gameObject))
    {
        Vector2 pos = gameObject.getPosition();
        
        fillOldGameObjectPositionToBackgroundColor(gameObject);
        
        int sizeX = (int)(gameObject.getSize().x * SIZE_MULTIPLIER);
        int sizeY = (int)(gameObject.getSize().y * SIZE_MULTIPLIER);
        int screenX = (int)(pos.x * SIZE_MULTIPLIER);
        int screenY = (int)((float(MAP_HEIGHT) - pos.y - gameObject.getSize().y) * SIZE_MULTIPLIER);
        
        
        if (gameObject.isActive())
        {
            
            bool hasVisiblePart = (screenX + sizeX > 0 && screenX < REAL_WIDTH && screenY + sizeY > 0 && screenY < REAL_HEIGHT);
            if (hasVisiblePart)
            {
                textureDrawer.drawTexture(display, gameTextures.getTexturePixelsByObjectType(gameObject.getType()), screenX, screenY, gameObject.getSize());
            }
        }
        else
        {
            display.fillDisplayRect(screenX, screenY, sizeX, sizeY, BACKGROUND_COLOR);
        }
    }
}

void Renderer::renderText(const char* text, Vector2 textPosition, Vector2 backgroundSize, size_t textSize, uint16_t textColor)
{
    display.fillDisplayRect(textPosition.x, textPosition.y, backgroundSize.x, backgroundSize.y, BACKGROUND_COLOR);
    display.setDisplayTextSize(textSize);
    display.setDisplayCursorPosition(textPosition.x, textPosition.y);
    display.printText(text);
    
}


bool Renderer::needRenderObject(GameObject& gameObject)
{
    if (gameObject.getType() == NONE) return false;
    if (gameObject.getPosition() == gameObject.getLastRenderedPosition() && gameObject.isActive() == gameObject.getLastRenderedActive()) return false;

    return true;
}

void Renderer::fillOldGameObjectPositionToBackgroundColor(GameObject& gameObject)
{
    Vector2 lastPosition = gameObject.getLastRenderedPosition();
    Vector2 currentPosition = gameObject.getPosition();

    if (lastPosition.x == currentPosition.x && lastPosition.y == currentPosition.y)
    {
        return;
    }
    
    if (lastPosition.x >= 0 && lastPosition.x <= MAP_WIDTH && lastPosition.y >= 0 && lastPosition.y <= MAP_HEIGHT)
    {
        int sizeX = (int)(gameObject.getSize().x * SIZE_MULTIPLIER);
        int sizeY = (int)(gameObject.getSize().y * SIZE_MULTIPLIER);
        
        int oldPositionX = (int)(lastPosition.x * SIZE_MULTIPLIER);
        int oldPositionY = (int)(((float)MAP_HEIGHT - lastPosition.y - gameObject.getSize().y) * SIZE_MULTIPLIER);
        
        if (oldPositionX >= 0 && oldPositionX < REAL_WIDTH && oldPositionY >= 0 && oldPositionY < REAL_HEIGHT)
        {
            display.fillDisplayRect(oldPositionX, oldPositionY, sizeX, sizeY, BACKGROUND_COLOR);
        }
    }
    
    gameObject.writeLastRenderedPosition();
    gameObject.writeLastRenderedActive();
}