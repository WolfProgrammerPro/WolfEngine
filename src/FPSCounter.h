#pragma once
#include <Renderer.h>
#include <Utils.h>

class FPSCounter
{
public:
    void showFPS(Renderer& renderer);
private:
    unsigned long lastFpsShow;
    unsigned int framesRendered;

};