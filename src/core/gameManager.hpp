#pragma once
#include <myMain.h>
#include <entityManager.hpp>
#include <gameInputs.hpp>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>
#include <ressourcesLoader.hpp>
#include <string>

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
  void render(sf::RenderWindow &window);
  gameManager(ressourceManager &instance_res) : res{instance_res} {

gameManager::clock.start();
  }
};