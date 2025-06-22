#pragma once

#include <SFML/Graphics.hpp>
#include <animatedSprite.hpp>

/// @brief state of entity, update animation each time when state changes
class entityState {
  
  int currentState = 0;
  int currentDirection = 0;
  
  public:
  enum state { IDLE = 0, MOVING = 1, FLYING = 2 };
  enum direction { UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3 };
  int getState();
  int getIdAnim();
  int changeIdAnim(animatedSprite &varAnim);


  void setCurrentDirection(int dir);

  void toIdle(int dir = -1);
  void isMoving(int dir = -1);
    void isFlying();


  int getAxisMoving(sf::Vector2f direction);

  void moveDirection(sf::Vector2i normalized_dir);

  sf::Vector2i dirToVecDir(int dir);
  int vecDirToDir(sf::Vector2f);
};