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
  entity_manager.swapStateToMoveEntities(GameDatas::ratioMovePNJStart);
}



void gm::render(sf::RenderWindow &window) {
  entity_manager.swapStateToMoveEntities(GameDatas::ratioMovePNJGameLoop);
  entity_manager.swapStateToIdleEntities(GameDatas::ratioIdlePNJGameLoop);
  entity_manager.moveEntities();

  entity_manager.renderEntities(window);
}

int gameManager::deltaTime() { return deltaTime_calculated.asMilliseconds(); }

void gameManager::setDeltaTime() {
  deltaTime_calculated = gameManager::clock.restart();
}

void gameManager::callInputEvent(){
  getInputsKeyboard();
}