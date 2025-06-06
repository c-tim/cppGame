#pragma once
#include <myMain.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Entity {
 protected:
  const int id;
  const std::string type;

  /// @brief the position at the feet of the entity (natural position)
  const sf::Vector2f feet_position;

  // TODO add Texture displayed and methods to get the position rendered with
  // the feet_position

 public:
  Entity(const int id, std::string const& type, sf::Vector2f position)
      : id{id}, type{type}, feet_position{position} {}

  // TODO not quite understood what exactly this do but prevent copy const
  // variables
  Entity(const Entity&) = delete;
  Entity& operator=(const Entity&) = delete;

   std::string to_string();

  // std::ostream& operator<<(std::ostream& os);

  virtual void render(sf::RenderWindow window) = 0;

  // easier than operator<< but should fix issue later (TODO)
};