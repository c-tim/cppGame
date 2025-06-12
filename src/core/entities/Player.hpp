#pragma once

#include <animatedSprite.hpp>
#include <gameDatas.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>

#include "Entity.hpp"

class player : public Entity {
 private:
 int cooldown_plant_crop = 10000;
 int tick_since_last_plant_crop = 0;

 public:
  player(int id, sf::Vector2f position, ressourceManager& res)
      : Entity(id, "player", position, res.humanAnimations, 0.2,
               GameDatas::humanSpeed, true) {
    // aSprite = res.humanAnimations;
    //  aSprite.addAnimation("walkLeft", "walk", 30);
  }
  bool canPlantCrop();
  void updateCooldowns();
  void resetCooldownPlantCrop();

  void render(sf::RenderWindow& window) override;

  void move() override ;

};