#include <Human.hpp>
#include <gameManager.hpp>
#include <inputManager.hpp>
#include <iostream>

using std::cout;

// TODO ask if good practice
#define gm gameManager

sf::Time gameManager::deltaTime_calculated;
sf::Clock gameManager::clock;

gameManager *gameManager::instance;


void gm::initialize_game() {
  currentGameState = gameState::InGame;
  entity_manager.generateHumans(GameDatas::spawned_pnj, res);
  entity_manager.generatePlayer(res);
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJStart);

}

void gm::applyGameLoopAndRender(sf::RenderWindow &window) {
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJGameLoop);
  entity_manager.swapStateToIdlePNJEntities(GameDatas::ratioIdlePNJGameLoop);
  entity_manager.moveEntities();

  entity_manager.checkInputOtherActionsPlayers(res);

  checkIfHumanClicked(window);
  res.renderTilemap(window);
  entity_manager.renderEntities(window);
}

int gameManager::deltaTimeMilli() { return deltaTime_calculated.asMilliseconds(); }

sf::Time gameManager::deltaTime() { return deltaTime_calculated; }


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

void gameManager::OnMouseClicked(sf::Vector2f mousePos){
  instance->entity_manager.moveSelectedEntityOrUnSelectIt(mousePos);
}

     void gameManager::movePlayerSelected(sf::Vector2f mousePos){
      instance->entity_manager.moveSelectedPlayerToMouse(mousePos);
     }


  void gameManager::callEntityManagerFaitLAppel(){
    entity_manager.faitLAppel();
  }


