#pragma once

#include <SFML/Graphics.hpp>
#include <animatedSprite.hpp>

/// @brief state of entity, update animation each time when state changes
class entityState {
  enum state { IDLE = 0, MOVING = 1 };
  enum direction { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 };

  int currentState = 0;
  int currentDirection = 0;

 public:
  int getState();
  int getIdAnim();
  int changeIdAnim(animatedSprite &varAnim);


  void setCurrentDirection(int dir, animatedSprite &varAnim);

  void toIdle(animatedSprite &varAnim, int dir = -1);
  void isMoving(int dir = -1);

  int getAxisMoving(sf::Vector2f direction, animatedSprite &varAnim);

  void moveDirection(sf::Vector2f normalized_dir, animatedSprite &varAnim);

  sf::Vector2f dirToVecDir(int dir);
  int vecDirToDir(sf::Vector2f);
};