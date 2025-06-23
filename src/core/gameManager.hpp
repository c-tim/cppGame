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
enum class gameState { StartMenu = 0, InGame = 1, CantMove = 2, ENDGAME = 3 };

class gameManager {
 private:
  entityManager entity_manager;
  ressourceManager res;

  // static sf::Time last_calculated_time;
  static sf::Time deltaTime_calculated;
  static sf::Clock clock;

  int numberHiders = 1;
  int currentHidersBusted = 0;

 public:
  int Score = 0;
  int numberPlayer = GameDatas::number_players;
  void newPlayerBusted();

  gameState currentGameState = gameState::InGame;

  static gameManager *instance;

  // Function linked to game events, called using instance
  bool newCropPlanted(sf::Vector2f pos);
  void OnMouseLeftClicked(sf::Vector2f mousePos);
  void OnMouseRightClicked(sf::Vector2f mousePos);
  void movePlayerSelected(sf::Vector2f mousePos);
  void addScore(int Score);
  void callEntityManagerFaitLAppel();
  void initialize_game();
  void renderScore(sf::RenderWindow &window);
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
    gameManager::clock.start();
  }
};