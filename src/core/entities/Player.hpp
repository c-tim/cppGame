#pragma once
#include <animatedSprite.hpp>
#include <defaultVisitor.hpp>
#include <gameDatas.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>

#include "Entity.hpp"

//#define key sf::Keyboard::Key

struct player_info {
  sf::Keyboard::Key keyUp = sf::Keyboard::Key::P;
  sf::Keyboard::Key keyLeft= sf::Keyboard::Key::P;
  sf::Keyboard::Key keyDown= sf::Keyboard::Key::P;
  sf::Keyboard::Key keyRight= sf::Keyboard::Key::P;
  sf::Keyboard::Key keyPlant= sf::Keyboard::Key::P;

  int curent_cooldownPlant = 0;
};


class player : public Entity {
 private:
  int cooldown_plant_crop = 10000;
  bool isPicked = false;
  
  void checkForBoundaries();
  
  public:
  int tick_since_last_plant_crop = 0;
  player_info keyPlayer{};

  player(int id, sf::Vector2f position, ressourceManager& res)
      : Entity(id, "player", position, res.humanAnimations,
               GameDatas::humanSize, true, GameDatas::humanSpeed, true){
    // aSprite = res.humanAnimations;
    //  aSprite.addAnimation("walkLeft", "walk", 30);
  }
  bool canPlantCrop();
  void updateCooldowns();
  void resetCooldownPlantCrop();

  void render(sf::RenderWindow& window) override;
  void accept(defaultVisitor* vis) const override;

  void move() override;
  void setPicked(bool picked);
};