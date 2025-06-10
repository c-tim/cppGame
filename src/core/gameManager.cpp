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
  entity_manager.generatePlayer(res);
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJStart);
}



void gm::applyGameLoopAndRender(sf::RenderWindow &window) {
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJGameLoop);
  entity_manager.swapStateToIdlePNJEntities(GameDatas::ratioIdlePNJGameLoop);
  entity_manager.movePNJEntities();
  entity_manager.movePlayers();

  entity_manager.renderEntities(window);
}

int gameManager::deltaTime() { return deltaTime_calculated.asMilliseconds(); }

void gameManager::setDeltaTime() {
  deltaTime_calculated = gameManager::clock.restart();
}

void gameManager::callInputEvent(){
  getInputsKeyboard();
}