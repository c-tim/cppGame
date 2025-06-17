#include <Human.hpp>
#include <gameManager.hpp>
#include <inputManager.hpp>
#include <iostream>

#include "Player.hpp"
using std::cout;

// TODO ask if good practice
#define gm gameManager

sf::Time gameManager::deltaTime_calculated;
sf::Clock gameManager::clock;

gameManager *gameManager::instance;

void gm::initialize_game() {
  currentGameState = gameState::InGame;
  entity_manager.generateHumans(GameDatas::spawned_pnj, res);
  for (int i = 0; i < numberPlayer; i++)
  {
    entity_manager.generatePlayer(res, i);
  }
  
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJStart);
}

void gm::applyGameLoopAndRender(sf::RenderWindow &window) {
  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJGameLoop);
  entity_manager.swapStateToIdlePNJEntities(GameDatas::ratioIdlePNJGameLoop);
  entity_manager.tick_since_lastPlant_grow+=deltaTimeMilli();
  entity_manager.moveEntities();

  entity_manager.checkInputOtherActionsPlayers(res);

  checkIfHumanClicked(window);
  res.renderTilemap(window);
  entity_manager.renderEntities(window);
  renderScore(window);
}

 void gameManager::renderScore(sf::RenderWindow &window){
  //sf::RectangleShape shape({70,40});
   // shape.setFillColor(sf::Color::Green);
    sf::Text t{res.fontGame,"Score : "+std::to_string(Score)};
    t.setPosition({700,0});
    //shape.setPosition({100,0});
   // window.draw(shape);
    window.draw(t);

 }

int gameManager::deltaTimeMilli() {
  return deltaTime_calculated.asMilliseconds();
}

sf::Time gameManager::deltaTime() { return deltaTime_calculated; }

void gameManager::setDeltaTime() {
  deltaTime_calculated = gameManager::clock.restart();
}

void gameManager::callInputEvent() {
  // getInputsKeyboard();
}

bool gameManager::newCropPlanted(sf::Vector2f pos) {
  instance->entity_manager.addCropPoseToQueue(pos);
  addScore(100);
  return true;
}

void gameManager::OnMouseLeftClicked(sf::Vector2f mousePos) {
  instance->entity_manager.moveSelectedEntityOrUnSelectIt(mousePos);
}

void gameManager::OnMouseRightClicked(sf::Vector2f mousePos) {
  player * playerSelected = instance->entity_manager.getPlayerSelected();
if(playerSelected->playable){
  //TODO temp solution, only one hider for the moment, so newPlayerBusted end the game
  instance->newPlayerBusted();
}
}

void gameManager::movePlayerSelected(sf::Vector2f mousePos) {
  instance->entity_manager.moveSelectedPlayerToMouse(mousePos);
}

void gameManager::callEntityManagerFaitLAppel() { entity_manager.faitLAppel(); }


void gameManager::addScore(int score){
 instance->Score+=score;
}

