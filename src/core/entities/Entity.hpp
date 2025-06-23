#pragma once

// TODO make the pattern visitor work, circular dependence makes a lot of errors
// in the class that inherist Entity I dont understand !!!
#include <defaultVisitor.hpp>
// #include <../core/behaviourVisitor/defaultVisitor.hpp>
#include <myMain.h>

#include <SFML/Graphics.hpp>
#include <animatedSprite.hpp>
#include <entityState.hpp>
#include <iostream>
#include <string>

class DeafaultVisitor;
// class defaultVisitor;

class Entity {
 protected:
  float speed;

  const int id;
  const std::string type;

  
  animatedSprite aSprite;
  
  /// @brief the position at the feet of the entity (natural position)
  sf::Vector2f feet_position;
  
  sf::Vector2f destination;
  
  // TODO add Texture displayed and methods to get the position rendered with
  // the feet_position
  
  public:
  entityState state;
  bool playable;
  int zOrder = 0 ; //the highest zOrder is rendered first (sprite behind the others)
  virtual ~Entity() {};
  sf::Vector2f getPosition();

  void setPosition(sf::Vector2f pos);

  bool canHaveNewDestination();
float scale;
  bool has_destination = false;
  const bool pickable;

  Entity(const int id, std::string const& type, sf::Vector2f position,
         animatedSprite& templateAnimatedSprite, float scale, bool isPickable ,float speed = 1,
         bool isPlayable = false)
      : id{id},
        type{type},
        feet_position{position},
        scale{scale},
        aSprite{templateAnimatedSprite},
        speed{speed},
        playable{isPlayable},
        pickable{isPickable}
         {
    state.toIdle();
  }

  virtual void accept(defaultVisitor* vis) const = 0;


  std::string to_string();

  void moveToDestination();

  sf::Vector2f getDirectionFromDestination();

  void moveWithDir(sf::Vector2f dir);

  void setDestination(sf::Vector2f destination);

  void toIdle(entityState::s_direction dir = entityState::s_direction::UNDEFINED);

  bool isMoving();

  virtual void render(sf::RenderWindow& window) = 0;

  virtual void move() = 0;

  bool isSpriteInBoundOfPos(sf::Vector2f pos) const;

};