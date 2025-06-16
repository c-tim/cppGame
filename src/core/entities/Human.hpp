#pragma once
#include <defaultVisitor.hpp>
#include <animatedSprite.hpp>
#include <ostream>
#include <ressourcesLoader.hpp>


#include "Entity.hpp"
#include <gameDatas.hpp>



class Human : public Entity {
 private:
 bool isPicked = false;
 public:
  Human(int id, sf::Vector2f position, ressourceManager &res) : Entity(id, "Human", position, res.humanAnimations, 0.2,true,GameDatas::humanSpeed)  {
    //aSprite = res.humanAnimations;
    // aSprite.addAnimation("walkLeft", "walk", 30);
  }

  void render( sf::RenderWindow &window) override;
  void accept( defaultVisitor *vis) const override;


  void move() override;

  void setPicked(bool picked);
};