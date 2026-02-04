#pragma once
#include <Renderer.h>

class FPSCounter
{
public:
    void showFPS(Renderer& renderer);
private:
    unsigned long lastFpsShow;
    unsigned int framesRendered;

};