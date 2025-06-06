#pragma once

#include <ostream>

#include "Entity.hpp"

class Human : public Entity {
 public:
  Human(int id, sf::Vector2f position) : Entity(id, "Human", position) {}
  void render(sf::RenderWindow window) override;

};