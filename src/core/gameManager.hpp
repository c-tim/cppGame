#pragma once
#include <myMain.h>
#include <entityManager.hpp>
#include <inputManager.hpp>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>
#include <ressourcesLoader.hpp>
#include <string>

//TODO for later
enum class gameState {StartMenu=0, InGame=1, CantMove=2};

class gameManager {
 private:



  entityManager entity_manager;
  ressourceManager &res;

  // static sf::Time last_calculated_time;
  static sf::Time deltaTime_calculated;
  static sf::Clock clock;


 public:

  void initialize_game();
  static int deltaTime();
  static void setDeltaTime();
  static void callInputEvent();
  void applyGameLoopAndRender(sf::RenderWindow &window);
  gameManager(ressourceManager &instance_res) : res{instance_res} {

gameManager::clock.start();
  }
};