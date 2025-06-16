#pragma once
#include <defaultVisitor.hpp>
#include <SFML/Graphics.hpp>

class Entity;

class spriteClickedVisitor : defaultVisitor {
 private :
 mutable const Entity* save_ptr_entity_selected;
  public:
  sf::Vector2f mousePos;
  // visitor called once so perdorm in the constructor
  explicit spriteClickedVisitor() {

  }

  void setMousePos(sf::Vector2f mousePos);

  void visitHuman(const Human *element) const override;
  void visitPlayer(const player *element) const override;
  void visitCrop(const crop *element) const override;

  Entity* getPickableEntitySelected(std::vector<std::unique_ptr<Entity>> *list);

};
