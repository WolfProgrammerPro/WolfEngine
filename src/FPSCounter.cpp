#include <FPSCounter.h>

void FPSCounter::showFPS(Renderer& renderer)
{
    if (getMillis() - lastFpsShow >= FPS_SHOW_DELAY)
    {
        lastFpsShow = getMillis();
        char fpsStr[20];
        short fps = (short)(framesRendered / FPS_SHOW_DELAY);
        sprintf(fpsStr, "FPS: %d", (int)fps);

        framesRendered = 0;
        renderer.renderText(
            fpsStr, 
            Vector2{FPS_TEXT_POSITION_X, FPS_TEXT_POSITION_Y}, 
            Vector2{FPS_BACKGROUND_SIZE_X, FPS_BACKGROUND_SIZE_Y},
            FPS_TEXT_SIZE, 
            FPS_TEXT_COLOR
        );
    }
    else
    {
        framesRendered++;
    }
}