#include <FPSCounter.h>

void FPSCounter::showFPS(Renderer& renderer)
{
    if (millis() - lastFpsShow >= FPS_SHOW_DELAY)
    {
        lastFpsShow = millis();
        String fps = "FPS: "+ String((int)((float)(framesRendered)/FPS_SHOW_DELAY));
        framesRendered = 0;
        renderer.renderText(fps, Vector2{FPS_TEXT_POSITION_X, FPS_TEXT_POSITION_Y}, Vector2{FPS_BACKGROUND_SIZE_X, FPS_BACKGROUND_SIZE_Y},FPS_TEXT_SIZE, FPS_TEXT_COLOR);
    }
    else
    {
        framesRendered++;
    }
}