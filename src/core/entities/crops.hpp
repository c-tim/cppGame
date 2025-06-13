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
 //TODO just why ?? patateAnimation is set exactly like humanAnimations, but it wont work, for now player plant dead human
 //UPDATE maybe wrong animselection with an horrible offset
  crop(int id, sf::Vector2f position, ressourceManager &res) : Entity(id, "Crop", position, res.humanAnimations, 10, GameDatas::humanSpeed, false)  {
    //aSprite.setCurrentAnim(0);
    // aSprite.addAnimation("walkLeft", "walk", 30);
  }

  void accept( defaultVisitor *vis) const override;

  void render( sf::RenderWindow &window) override;

  void move() override;
}; 