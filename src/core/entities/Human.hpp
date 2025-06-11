#pragma once

#include <animatedSprite.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>

#include "Entity.hpp"
#include <gameDatas.hpp>

class Human : public Entity {
 private:
 public:
  Human(int id, sf::Vector2f position, ressourceManager &res) : Entity(id, "Human", position, res.humanAnimations, GameDatas::humanSpeed)  {
    //aSprite = res.humanAnimations;
    // aSprite.addAnimation("walkLeft", "walk", 30);
  }

  void render( sf::RenderWindow &window) override;

  void move() override;
};