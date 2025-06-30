#pragma once

#include <Entity.hpp>
#include <Player.hpp>
#include <SFML/Graphics.hpp>
#include <gameDatas.hpp>
#include <iostream>
#include <ressourcesLoader.hpp>
#include <spriteClickedVisitor.hpp>

sf::Vector2f random_pos_in_playable_area();
void setPlayerInfo(int index, struct player_info &info);

class entityManager {
 private:
  int idNextEntity = 0;

  std::vector<std::unique_ptr<Entity>> spawned_entities;

  // TODO maybe bad practice but I dont know alternative to access unique
  // behaviour from player
  //  and have them in a sortable list with entities for zorder
  std::vector<player *> players;

  // store the pos of the planted_crops so that it wont affect list of pointer
  // spawned_entities during sensitive access
  std::vector<sf::Vector2f> crop_to_plant_queue;

  static bool compZOrderEntity(std::unique_ptr<Entity> &a,
                               std::unique_ptr<Entity> &b);
  void sortEntityByZOrder(std::vector<std::unique_ptr<Entity>> &list_entities);
  spriteClickedVisitor sprite_clicked_visitor;

 public:
  int tick_since_lastPlant_grow = 0;
  Entity *currentEntitySelected = nullptr;

  void swapStateToMovePNJEntities(float ratioToMove);
  void swapStateToIdlePNJEntities(float ratioToIdle);

  void moveEntities();
  void renderEntities(sf::RenderWindow &window);

  void checkInputOtherActionsPlayers(ressourceManager &res);
  void addCropPoseToQueue(sf::Vector2f pos);

  void generatePlayer(ressourceManager &res, int indexPlayer);
  void generateHuman(ressourceManager &res);
  void generateHumans(int count, ressourceManager &res);
  void generateCrop(ressourceManager &res, sf::Vector2f pos);
  void destroyEntity(Entity *entity_to_destroy);

  void addEntity(Entity *entity);

  void faitLAppel();

  void moveSelectedEntityOrUnSelectIt(sf::Vector2f mousePos);
  void moveSelectedPlayerToMouse(sf::Vector2f mousePos);
  Entity *getEntitySelected();

  Entity *getPickableEntitySelected(std::vector<std::unique_ptr<Entity>> *list,
                                    sf::Vector2f mousePos);
};