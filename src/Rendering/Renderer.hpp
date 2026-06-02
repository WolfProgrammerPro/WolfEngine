#pragma once

#include <Engine\Utils.hpp>
#include <Hardware\Board.hpp>
#include <GameObjects\GameObject.hpp>
#include <Hardware\Display.hpp>
#include <Rendering\TextureDrawer.hpp>
#include <Engine\GameTextures.hpp>



class Renderer
{
public:
    Renderer();
    void setScreenColor(uint16_t color);
    void render(GameObject* gameObjects);
    void renderObject(GameObject& gameObject);
    void renderText(const char* text, Vector2 textPosition, Vector2 backgroundSize, size_t textSize, uint16_t textColor);
    inline void initDisplay() {display.initDisplay();}
private:
    Display display;
    TextureDrawer textureDrawer;
    GameTextures gameTextures;
    bool needRenderObject(GameObject& gameObject);
    void fillOldGameObjectPositionToBackgroundColor(GameObject& gameObject);
};