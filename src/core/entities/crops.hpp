#pragma once

#include <animatedSprite.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>

#include <defaultVisitor.hpp>
#include "Entity.hpp"
#include <gameDatas.hpp>

class crop : public Entity {
 private:
 public:
  crop(int id, sf::Vector2f position, ressourceManager &res) : Entity(id, "Crop", position, res.patateAnimations, 100, false,0, false)  {
   zOrder = 1; //behind every Sprite
  }

  void accept( defaultVisitor *vis) const override;

  void render( sf::RenderWindow &window) override;

  void move() override;
}; 