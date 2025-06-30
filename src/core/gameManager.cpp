#include <Human.hpp>
#include <gameManager.hpp>
#include <inputManager.hpp>
#include <iostream>

#include "Player.hpp"
using std::cout;

// TODO ask if good practice
#define gm gameManager

sf::Time gameManager::deltaTime_calculated;
sf::Clock gameManager::deltaClock;

gameManager *gameManager::instance;

void gm::initialize_startMenu() {
  currentGameState = gameState::StartMenu;
  res.initializeStartMenu();
}

void gm::prepareGameLoop() {
  res.initializeRessourcesGame();
  // currentGameState = gameState::InGame;
  entity_manager.generateHumans(GameDatas::spawned_pnj, res);
  for (int i = 0; i < numberPlayer; i++) {
    entity_manager.generatePlayer(res, i);
  }

  entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJStart);
  res.ressourceGameLoopReady();
}

void gm::launchGame() {
  currentGameState = gameState::InGame;
  gameLoopClock.restart();
}

void gm::applyGameLoopAndRender(sf::RenderWindow &window) {
  if (currentGameState == gameState::StartMenu) {
    res.renderStartGame(window);

    // si les ressources pour InGame ont été chargés on peut afficher le texte
    // indiquant d'appuyer sur space
    if (res.isCurrentRessourcesGameStateLoaded(gameState::InGame)) {
      drawText("Press SPACE to start !", {800, 900}, window);
      if (isSpacePressed()) {
        launchGame();
      }
    }

  } else if (currentGameState == gameState::InGame) {
    entity_manager.swapStateToMovePNJEntities(GameDatas::ratioMovePNJGameLoop);
    entity_manager.swapStateToIdlePNJEntities(GameDatas::ratioIdlePNJGameLoop);
    entity_manager.tick_since_lastPlant_grow += deltaTimeMilli();
    entity_manager.moveEntities();

    entity_manager.checkInputOtherActionsPlayers(res);

    checkIfHumanClicked(window);

    if (getRemainingTime() <= 0) {
      gameFinished();
    }

    renderAllElements(window);

  } else if (currentGameState == gameState::CantMove) {
    entity_manager.swapStateToIdlePNJEntities(1);
    renderAllElements(window);

    if (res.isCurrentRessourcesGameStateLoaded(gameState::ENDGAME)) {
      currentGameState = gameState::ENDGAME;
    }
  } else {
    res.renderEndMenu(haveHidersWon, window);
    if (haveHidersWon) {
      drawText("Hiders Win !!", {800, 0}, window, sf::Color::Blue);
    } else {
      drawText("Finder Wins !!", {800, 0}, window, sf::Color::Red);
    }

    drawText("Press SPACE to quit !", {800, 900}, window, sf::Color::Yellow);

    if (isSpacePressed()) {
      currentGameState = gameState::QUIT;
    }
  }
}

void gameManager::gameFinished() {
  currentGameState = gameState::CantMove;
  haveHidersWon = Score >= getScoretoWin();
  gameLoopClock.stop();
  res.initializeEndMenu();
}

void gameManager::renderAllElements(sf::RenderWindow &window) {
  res.renderTilemap(window);
  entity_manager.renderEntities(window);
  renderScoreAndTime(window);
}

void gameManager::renderScoreAndTime(sf::RenderWindow &window) {
  drawText("Score : " + std::to_string(Score), {800, 0}, window);
  drawText(std::to_string(getRemainingTime()), {1700, 0}, window);
}

void gameManager::drawText(std::string text, sf::Vector2f pos,
                           sf::RenderWindow &window, sf::Color col) {
  sf::Text t{res.fontGame, text};
  t.setPosition(pos);
  t.setFillColor(col);
  window.draw(t);
}

int gameManager::deltaTimeMilli() {
  return deltaTime_calculated.asMilliseconds();
}

sf::Time gameManager::deltaTime() { return deltaTime_calculated; }

void gameManager::setDeltaTime() {
  deltaTime_calculated = gameManager::deltaClock.restart();
}

bool gameManager::newCropPlanted(sf::Vector2f pos) {
  instance->entity_manager.addCropPoseToQueue(pos);
  addScore(GameDatas::pointsWonCropsPlanted);
  return true;
}

void gameManager::OnMouseLeftClicked(sf::Vector2f mousePos) {
  instance->entity_manager.moveSelectedEntityOrUnSelectIt(mousePos);
}

void gameManager::OnMouseRightClicked(sf::Vector2f mousePos) {
  Entity *entitySelected = instance->entity_manager.getEntitySelected();
  if (entitySelected == nullptr) {
    return;
  }
  instance->entity_manager.destroyEntity(entitySelected);
  if (entitySelected->playable) {
    // TODO temp solution, only one hider for the moment, so newPlayerBusted end
    // the game
    instance->newPlayerBusted();
  } else {
    instance->wrongEntityBusted();
  }
  entitySelected = nullptr;
}

void gameManager::movePlayerSelected(sf::Vector2f mousePos) {
  instance->entity_manager.moveSelectedPlayerToMouse(mousePos);
}

void gameManager::callEntityManagerFaitLAppel() { entity_manager.faitLAppel(); }

void gameManager::addScore(int score) { instance->Score += score; }

void gameManager::newPlayerBusted() {
  currentHidersBusted++;
  if (currentHidersBusted >= GameDatas::number_players) {
    gameFinished();
  }
}

void gameManager::wrongEntityBusted() {
  // les personnes cachés gagnent des points pour chaque erreur du trouveur
  addScore(GameDatas::pointsWonCropsPlanted);
}

int gameManager::getScoretoWin() {
  return GameDatas::pointsToHidersWin +
         GameDatas::number_players *
             GameDatas::pointToHidersAddedForEachedHider;
}

int gameManager::getRemainingTime() {
  return GameDatas::durationGameSeconds -
         gameLoopClock.getElapsedTime().asSeconds();
}