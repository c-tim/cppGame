#pragma once
#include <myMain.h>

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class gameManager {
 private:
  std::vector<Entity> spawned_entities;

  void generatePNJ();
  void generatePNJs(int count);

 public:
  gameManager() {}
};