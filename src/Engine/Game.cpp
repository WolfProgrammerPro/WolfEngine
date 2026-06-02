#include <Engine\Game.hpp>

void Game::start()
{
    initBoard();
    restarter.init(mapsManager);
    mapsManager.init(restarter);
    renderer.initDisplay();
    renderer.setScreenColor(COLOR_BLACK);
}

void Game::update()
{
    mapsManager.update(renderer);
}