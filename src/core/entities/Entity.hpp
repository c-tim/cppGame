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

  //TODO add Texture displayed and methods to get the position rendered with the feet_position



  virtual void render(sf::RenderWindow window) = 0;

 public:
  Entity(int id, std::string const &type, sf::Vector2f position)
      : id{id}, type{type}, feet_position{position} {}
};