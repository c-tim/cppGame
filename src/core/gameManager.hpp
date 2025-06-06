#pragma once
#include <myMain.h>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>
#include <string>

class gameManager {
 private:
  int idNextEntity = 0;
  std::vector<std::unique_ptr<Entity>> spawned_entities;

  void generatePNJ();
  void generatePNJs(int count);
  void addEntity(Entity *entity);

 public:
  void initialize_game();
  gameManager() {}
};