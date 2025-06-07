#pragma once
#include <myMain.h>
#include <entityState.hpp>
#include <animatedSprite.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Entity {
 protected:

  float speed;

  const int id;
  const std::string type;

  entityState state;

  animatedSprite &aSprite;



  /// @brief the position at the feet of the entity (natural position)
  sf::Vector2f feet_position;

  sf::Vector2f destination;

  // TODO add Texture displayed and methods to get the position rendered with
  // the feet_position

 public:

  bool has_destination = false;

  Entity(const int id, std::string const& type, sf::Vector2f position, animatedSprite &templateAnimatedSprite, float speed=1)
      : id{id}, type{type}, feet_position{position}, aSprite{templateAnimatedSprite}, speed{speed}{
        state.toIdle(aSprite.currentAnim);
      }

  // TODO not quite understood what exactly this do but prevent copy const
  // variables
  Entity(const Entity&) = delete;
  Entity& operator=(const Entity&) = delete;

   std::string to_string();

  // std::ostream& operator<<(std::ostream& os);


  void moveToDestination();

  void setDestination(sf::Vector2f destination);

  virtual void render( sf::RenderWindow &window) = 0;

  // easier than operator<< but should fix issue later (TODO)
};