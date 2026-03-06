#pragma once
#include <Rendering\Renderer.h>
#include <Engine\Utils.h>

class FPSCounter
{
public:
    void showFPS(Renderer& renderer);
private:
    unsigned long lastFpsShow;
    unsigned int framesRendered;

};