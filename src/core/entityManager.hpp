#pragma once

#include <Entity.hpp>
#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>
#include <ressourcesLoader.hpp>

class entityManager {
 private:
  int idNextEntity = 0;

  std::vector<std::unique_ptr<Entity>> spawned_entities;

  static bool compZOrderEntity(std::unique_ptr<Entity> &a,
                          std::unique_ptr<Entity> &b);
  void sortEntityByZOrder(std::vector<std::unique_ptr<Entity>> &list_entities);

 public:
  void swapStateToMoveEntities(float ratioToMove);
  void swapStateToIdleEntities(float ratioToIdle);

  void moveEntities();
  void renderEntities(sf::RenderWindow &window);

  void generateHuman(ressourceManager &res);
  void generateHumans(int count, ressourceManager &res);
  void addEntity(Entity *entity);
};