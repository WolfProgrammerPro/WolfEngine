#pragma once

#include <Utils.h>
#include <Board.h>
#include <GameObject.h>
#include <Display.h>




class Renderer
{
public:
    Renderer();
    void setScreenColor(uint16_t color);
    void render(const GameObject* const& gameObjects, size_t size);
    void renderPlayer(const GameObject& player);
    void renderObject(const GameObject& gameObject);
    void renderText(const char* text, Vector2 textPosition, Vector2 backgroundSize, size_t textSize, uint16_t textColor);
    inline void initDisplay() {display.initDisplay();}
    uint16_t getGameObjectColor(GameObjectType type);
private:
    Display display;
    Vector2 oldPlayerPosition;
};