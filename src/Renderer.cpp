#include <Renderer.h>

Renderer::Renderer() : oldPlayerPosition(Vector2{-1,-1}) {}


void Renderer::setScreenColor(uint16_t color)
{
    display.fillDisplayScreen(color);
}




void Renderer::render(const GameObject* const& gameObjects, size_t size)
{

    
    for (size_t i = 0; i < size; i++)
    {
        const GameObject& object = gameObjects[i];
        
        if (object.getType() != DOOR)
        {
            renderObject(object);
        }
        
    }

    for (size_t i = 0; i < size; i++)
    {
        const GameObject& object = gameObjects[i];
        
        if (object.getType() == DOOR)
        {
            renderObject(object);
        }
    }
}



void Renderer::renderPlayer(const GameObject& player)
{
    Vector2 playerPosition = player.getPosition();
    if (playerPosition != oldPlayerPosition)
    {
        if (oldPlayerPosition.x != -1)
        {
            int sizeX = player.getSize().x * SIZE_MULTIPLIER;
            int sizeY = player.getSize().y * SIZE_MULTIPLIER;
            int oldPlayerPositionX = oldPlayerPosition.x * SIZE_MULTIPLIER;
            int oldPlayerPositionY = (MAP_HEIGHT - oldPlayerPosition.y - player.getSize().y) * SIZE_MULTIPLIER;
            display.fillDisplayRect(oldPlayerPositionX, oldPlayerPositionY, sizeX, sizeY, COLOR_BLACK);
        }
        oldPlayerPosition = playerPosition;
        renderObject(player);
    }
}


void Renderer::renderObject(const GameObject& gameObject)
{
    GameObjectType type = gameObject.getType();
    if (type != NONE)
    {
        uint16_t color = getGameObjectColor(type);
        Vector2 pos = gameObject.getPosition();
        int sizeX = gameObject.getSize().x * SIZE_MULTIPLIER;
        int sizeY = gameObject.getSize().y * SIZE_MULTIPLIER;
        int screenX = pos.x * SIZE_MULTIPLIER;
        int screenY = (MAP_HEIGHT - pos.y - gameObject.getSize().y) * SIZE_MULTIPLIER;
        
        if (gameObject.isActive())
        {
            if (type == DOOR)
            {
                display.fillDisplayRect(screenX, screenY, sizeX, sizeY, COLOR_BLACK);
                display.drawDisplayRect(screenX, screenY, sizeX, sizeY, color);
            }
            else
            {
                display.fillDisplayRect(screenX, screenY, sizeX, sizeY, color);
            }
        }
        else
        {
            display.fillDisplayRect(screenX, screenY, sizeX, sizeY, COLOR_BLACK);
        }
    }  
}

uint16_t Renderer::getGameObjectColor(GameObjectType type)
{
    switch (type)
    {
        case NONE: return 0; break;
        case WALL: return COLOR_WHITE; break;
        case PLAYER: return COLOR_BLUE; break;
        case KEY: return COLOR_YELLOW; break;
        case DOOR: return COLOR_ORANGE; break;
        case FINISH: return COLOR_GREEN; break;
    }
    return 0;
}

void Renderer::renderText(const char* text, Vector2 textPosition, Vector2 backgroundSize, size_t textSize, uint16_t textColor)
{
    display.fillDisplayRect(textPosition.x, textPosition.y, backgroundSize.x, backgroundSize.y, COLOR_BLACK);
    display.setDisplayTextSize(textSize);
    display.setDisplayCursorPosition(textPosition.x, textPosition.y);
    display.printText(text);
    
}
