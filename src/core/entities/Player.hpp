#pragma once

#include <animatedSprite.hpp>
#include <gameDatas.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>

#include "Entity.hpp"

class player : public Entity {
 private:
 public:
  player(int id, sf::Vector2f position, ressourceManager& res)
      : Entity(id, "player", position, res.humanAnimations,
               GameDatas::humanSpeed, true) {
    // aSprite = res.humanAnimations;
    //  aSprite.addAnimation("walkLeft", "walk", 30);
  }

  void render(sf::RenderWindow& window) override;

};