#pragma once
#include <myMain.h>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <entityManager.hpp>
#include <gameEvents.hpp>
#include <inputManager.hpp>
#include <iostream>
#include <ressourcesLoader.hpp>
#include <string>

#include "gameDatas.hpp"

using std::cout;

// TODO for later
enum class gameState { UNDEFINED=-1, StartMenu = 0, InGame = 1, CantMove = 2, ENDGAME = 3 , QUIT=4};

class gameManager {
 private: 
  entityManager entity_manager;
  ressourceManager res;

  // static sf::Time last_calculated_time;
  static sf::Time deltaTime_calculated;
  static sf::Clock deltaClock;

  sf::Clock gameLoopClock;

  int numberHiders = 1;
  int currentHidersBusted = 0;

  void renderAllElements(sf::RenderWindow &window);
  void newPlayerBusted();
  void wrongEntityBusted();
  void launchGame();
  void gameFinished();

  int getScoretoWin();
  int getRemainingTime();

  bool haveHidersWon; 

 public:
  int Score = 0;
  int numberPlayer = GameDatas::number_players;

  gameState currentGameState = gameState::InGame;

  static gameManager *instance;

  // Function linked to game events, called using instance
  bool newCropPlanted(sf::Vector2f pos);
  void OnMouseLeftClicked(sf::Vector2f mousePos);
  void OnMouseRightClicked(sf::Vector2f mousePos);
  void movePlayerSelected(sf::Vector2f mousePos);
  void addScore(int Score);
  void callEntityManagerFaitLAppel();
  void initialize_startMenu();
  void prepareGameLoop();
  void renderScoreAndTime(sf::RenderWindow &window);
  void drawText(std::string text, sf::Vector2f pos, sf::RenderWindow &window ,sf::Color col = sf::Color::White);
  void applyGameLoopAndRender(sf::RenderWindow &window);

  int deltaTimeMilli();
  sf::Time deltaTime();
  void setDeltaTime();

  // constructor
  gameManager() : res{} {
    if (instance != nullptr) {
      cout << "ERROR instance already set\n";
      return;
    }
    instance = this;
    gameManager::deltaClock.start();
  }
};