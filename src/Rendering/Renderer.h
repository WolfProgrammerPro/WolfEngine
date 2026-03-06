#pragma once

#include <Engine\Utils.h>
#include <Hardware\Board.h>
#include <GameObjects\GameObject.h>
#include <Hardware\Display.h>
#include <Rendering\TextureDrawer.h>
#include <Engine\GameTextures.h>



class Renderer
{
public:
    Renderer();
    void setScreenColor(uint16_t color);
    void render(const GameObject* const& gameObjects, size_t size);
    void renderObject(const GameObject& gameObject);
    void renderText(const char* text, Vector2 textPosition, Vector2 backgroundSize, size_t textSize, uint16_t textColor);
    inline void initDisplay() {display.initDisplay();}
private:
    Display display;
    Vector2 oldPlayerPosition;
    TextureDrawer textureDrawer;
    GameTextures gameTextures;
    bool needRenderObject(const GameObject& gameObject);
    void fillOldGameObjectPositionToBackgroundColor(const GameObject& gameObject);
};