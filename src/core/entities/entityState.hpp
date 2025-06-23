#pragma once

#include <SFML/Graphics.hpp>
#include <animatedSprite.hpp>

/// @brief state of entity, update animation each time when state changes
class entityState {
 public:
  enum s_state { IDLE = 0, MOVING = 1, FLYING = 2 };
  enum s_direction { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3, UNDEFINED = -1 };
  s_state getState();
  int getIdAnim();
  int changeIdAnim(animatedSprite &varAnim);

  void setCurrentDirection(s_direction dir);

  void toIdle(s_direction dir = UNDEFINED);
  void isMoving(s_direction dir = UNDEFINED);
  void isFlying();

  s_direction getAxisMoving(sf::Vector2f direction);

  void moveDirection(sf::Vector2i normalized_dir);

  sf::Vector2i dirToVecDir(s_direction dir);
  s_direction vecDirToDir(sf::Vector2f);

 protected:
  s_state currentState = IDLE;
  s_direction currentDirection = UP;
};