#pragma once

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>
#include <Utils.h>

#include <GameObject.h>


#define TFT_CS   10
#define TFT_RST  8
#define TFT_DC   9

class Renderer
{
public:
    Renderer();
    void init();
    void setScreenColor(uint16_t color);
    void render(const GameObject* const& gameObjects, size_t size);
    void renderPlayer(const GameObject& player);
    void renderObject(const GameObject& gameObject);
    void renderText(String text, Vector2 textPosition, Vector2 backgroundSize, size_t textSize, uint16_t textColor);
    uint16_t getGameObjectColor(GameObjectType type);
private:
    Adafruit_ST7735 display;
    Vector2 oldPlayerPosition;
};