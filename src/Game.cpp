#include <Game.h>

Game::Game(){}

void Game::start()
{
    initBoard();
    renderer.initDisplay();
    renderer.setScreenColor(COLOR_BLACK);
    mapsManager.init(renderer);
}

void Game::loop()
{
    mapsManager.updateDinamicObjects(renderer);
    fpsCounter.showFPS(renderer);
}