#pragma once
#include <myMain.h>
#include <ressourcesLoader.hpp>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <entityManager.hpp>
#include <gameDatas.hpp>
#include <inputManager.hpp>
#include <iostream>
#include <string>
#include <gameEvents.hpp>



// TODO for later
enum class gameState { StartMenu = 0, InGame = 1, CantMove = 2 };

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
 void newPlayerBusted();

  gameState currentGameState = gameState::InGame;

  static gameManager *instance;



  static bool newCropPlanted(sf::Vector2f pos);

  static void OnMouseClicked(sf::Vector2f mousePos);

    static void movePlayerSelected(sf::Vector2f mousePos);


  void callEntityManagerFaitLAppel();

  void initialize_game();
  static int deltaTimeMilli();
  static sf::Time deltaTime() ;

  static void setDeltaTime();
  static void callInputEvent();
  void applyGameLoopAndRender(sf::RenderWindow &window);
  gameManager() : res{}{

    //gameEvent::setInstance(&this);
    //gameEvent::instance = this;
    instance = this;
    gameManager::clock.start();
  }
};