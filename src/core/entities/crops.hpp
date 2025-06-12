#pragma once

#include <animatedSprite.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>

#include "Entity.hpp"
#include <gameDatas.hpp>

class crop : public Entity {
 private:
 public:
  crop(int id, sf::Vector2f position, ressourceManager &res) : Entity(id, "Crop", position, res.patateAnimations, 10, GameDatas::humanSpeed, false)  {
    //aSprite.setCurrentAnim(0);
    // aSprite.addAnimation("walkLeft", "walk", 30);
  }

  void render( sf::RenderWindow &window) override;

  void move() override;
}; 