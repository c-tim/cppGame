#include <Human.hpp>
#include <gameManager.hpp>
#include <iostream>

using std::cout;

// TODO ask if good practice
#define gm gameManager

sf::Time gameManager::deltaTime_calculated;
sf::Clock gameManager::clock;

void gm::initialize_game() {
  entity_manager.generateHumans(GameDatas::spawned_pnj, res);
  entity_manager.swapStateEntities(0.5, 0.9);
}

void gm::render(sf::RenderWindow &window) {
  entity_manager.renderEntities(window);
  entity_manager.moveEntities();
}

int gameManager::deltaTime() { return deltaTime_calculated.asMilliseconds(); }

void gameManager::setDeltaTime() {
  deltaTime_calculated = gameManager::clock.restart();
}