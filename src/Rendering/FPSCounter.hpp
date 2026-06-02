#pragma once
#include <Rendering\Renderer.hpp>
#include <Engine\Utils.hpp>

class FPSCounter
{
public:
    void showFPS(Renderer& renderer);
private:
    unsigned long lastFpsShow;
    unsigned int framesRendered;

};