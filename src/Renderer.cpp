#include <Renderer.h>

Renderer::Renderer() : display(TFT_CS, TFT_DC, TFT_RST) , oldPlayerPosition(Vector2{-1,-1})
{
    
}

void Renderer::init()
{
    display.initR(INITR_BLACKTAB);
    display.setRotation(1);
}

void Renderer::setScreenColor(uint16_t color)
{
    display.fillScreen(color);
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
            display.fillRect(oldPlayerPositionX, oldPlayerPositionY, sizeX, sizeY, ST7735_BLACK);
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
                display.fillRect(screenX, screenY, sizeX, sizeY, ST7735_BLACK);
                display.drawRect(screenX, screenY, sizeX, sizeY, color);
            }
            else
            {
                display.fillRect(screenX, screenY, sizeX, sizeY, color);
            }
        }
        else
        {
            display.fillRect(screenX, screenY, sizeX, sizeY, ST7735_BLACK);
        }
    }  
}

uint16_t Renderer::getGameObjectColor(GameObjectType type)
{
    switch (type)
    {
        case NONE: return 0; break;
        case WALL: return ST77XX_WHITE; break;
        case PLAYER: return ST77XX_BLUE; break;
        case KEY: return ST7735_YELLOW; break;
        case DOOR: return ST7735_ORANGE; break;
        case FINISH: return ST7735_GREEN; break;
    }
    return 0;
}

void Renderer::renderText(String text, Vector2 textPosition, Vector2 backgroundSize, size_t textSize, uint16_t textColor)
{
    display.fillRect(textPosition.x, textPosition.y, backgroundSize.x, backgroundSize.y, ST7735_BLACK);
    display.setTextSize(textSize);
    display.setCursor(textPosition.x, textPosition.y);
    display.print(text);
}
