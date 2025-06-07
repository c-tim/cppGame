#pragma once

#include <animatedSprite.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>

#include "Entity.hpp"

class Human : public Entity {
 private:
  animatedSprite &aSprite;

 public:
  Human(int id, sf::Vector2f position, ressourceManager &res) : Entity(id, "Human", position), aSprite{res.humanAnimations} {
    //aSprite = res.humanAnimations;
    // aSprite.addAnimation("walkLeft", "walk", 30);
  }
  void render( sf::RenderWindow &window) override;
};