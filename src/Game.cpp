#include <Game.h>

Game::Game() : player(Vector2{STARTER_PLAYER_POSITION_X, STARTER_PLAYER_POSITION_Y}, Vector2{PLAYER_SIZE_X, PLAYER_SIZE_Y}) {}

void Game::start()
{
    Serial.begin(9600);  // Инициализация Serial для отладки
    Serial.println("Game starting...");
    
    initBoard();
    Serial.println("Board initialized");
    
    renderer.initDisplay();
    Serial.println("Display initialized");
    
    renderer.setScreenColor(COLOR_BLACK);
    Serial.println("Screen cleared");
    
    mapsManager.init(renderer);
    Serial.println("Map loaded");
}

void Game::loop()
{
    renderer.renderPlayer(player.getGameObject());
    mapsManager.renderDinamicObjects(renderer);
    player.update(mapsManager, renderer);
    fpsCounter.showFPS(renderer);
}