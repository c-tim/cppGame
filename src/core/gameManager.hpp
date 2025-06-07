#pragma once
#include <myMain.h>
#include <ressourcesLoader.hpp>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>
#include <string>

class gameManager {
 private:
  int idNextEntity = 0;
  std::vector<std::unique_ptr<Entity>> spawned_entities;
  ressourceManager &res;

  void generatePNJ();
  void generatePNJs(int count);
  void addEntity(Entity *entity);

 public:
  void initialize_game();
  void renderEntities( sf::RenderWindow &window);
  gameManager(ressourceManager &instance_res): res{instance_res} {}

};