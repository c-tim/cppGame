#pragma once

#include <Entity.hpp>
#include <ressourcesLoader.hpp>

#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>

class entityManager {
 private:
   int idNextEntity = 0;

  std::vector<std::unique_ptr<Entity>> spawned_entities;

 public:
  void swapStateEntities(float ratioToMove, float ratioToIdle);
  void moveEntities();
  void renderEntities(sf::RenderWindow &window);

  void generateHuman(ressourceManager &res);
  void generateHumans(int count,ressourceManager &res);
  void addEntity(Entity *entity);
};