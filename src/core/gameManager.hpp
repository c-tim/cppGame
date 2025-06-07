#pragma once
#include <myMain.h>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>
#include <ressourcesLoader.hpp>
#include <string>

class gameManager {
 private:
  int idNextEntity = 0;
  std::vector<std::unique_ptr<Entity>> spawned_entities;
  ressourceManager &res;

  // static sf::Time last_calculated_time;
  static sf::Time deltaTime_calculated;
  static sf::Clock clock;

  void generatePNJ();
  void generatePNJs(int count);
  void addEntity(Entity *entity);

 public:
  void initialize_game();
  void renderEntities(sf::RenderWindow &window);
  static int deltaTime();
  static void setDeltaTime();
  gameManager(ressourceManager &instance_res) : res{instance_res} {

gameManager::clock.start();
  }
};