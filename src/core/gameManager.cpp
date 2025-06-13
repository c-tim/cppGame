#include <Human.hpp>
#include <gameManager.hpp>
#include <iostream>

using std::cout;

// TODO ask if good practice
#define gm gameManager

sf::Time gameManager::deltaTime_calculated;
sf::Clock gameManager::clock;

gameManager *gameManager::instance;


void gm::initialize_game() {
  entity_manager.generateHumans(GameDatas::spawned_pnj, res);
  entity_manager.generatePlayer(res);
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJStart);
}

void gm::applyGameLoopAndRender(sf::RenderWindow &window) {
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJGameLoop);
  entity_manager.swapStateToIdlePNJEntities(GameDatas::ratioIdlePNJGameLoop);
  entity_manager.moveEntities();

  entity_manager.checkInputOtherActionsPlayers(res);

  entity_manager.renderEntities(window);
}

int gameManager::deltaTime() { return deltaTime_calculated.asMilliseconds(); }

void gameManager::setDeltaTime() {
  deltaTime_calculated = gameManager::clock.restart();
}

void gameManager::callInputEvent() {
  // getInputsKeyboard();
}

bool gameManager::newCropPlanted(sf::Vector2f pos) {
  instance->entity_manager.addCropPoseToQueue(pos);
  return true;
}

/*void gameManager::OnMouseClicked(sf::Vector2f mousePos){
  //Check if a entity is contained in this 
  //for(auto &e)
}*/

  void gameManager::callEntityManagerFaitLAppel(){
    entity_manager.faitLAppel();
  }
