#include <entityState.hpp>
#include <iostream>

using std::cout;

int entityState::getState() { return currentState; }

/* The animation are sorted in ressourceLoader.cpp to be in this order (Up Left Down Right)*/
int entityState::getIdAnim() { return (4 * currentState + currentDirection); }

int entityState::changeIdAnim(animatedSprite &varAnim) {
  varAnim.setCurrentAnim(4 * currentState + currentDirection);
  return 0;
}

void entityState::setCurrentDirection(int dir) {
  currentDirection = dir;
}

void entityState::toIdle(int dir) {
  currentState = IDLE;

  if (dir >= 0 && dir <= 3) {
    currentDirection = dir;
  }
}

void entityState::moveDirection(sf::Vector2i normalized_dir) {
  // the entity has to move in only one direction, no diagonals
  if (!((abs(normalized_dir.x) == 1 && normalized_dir.y == 0) ||
        (abs(normalized_dir.y) == 1 && normalized_dir.x == 0))) {
    cout
        << "Invalid normalized direction : the entity must move on one axis \n";
    return;
  }

  currentState = MOVING;
  currentDirection = vecDirToDir((sf::Vector2f)normalized_dir);
}


sf::Vector2i entityState::dirToVecDir(int dir) {
  // DONE check if correct vector -> unitTests
  if (dir == UP) {
    return sf::Vector2i{0, -1};
  } else if (dir == LEFT) {
    return sf::Vector2i{-1, 0};
  } else if (dir == DOWN) {
    return sf::Vector2i{0, 1};
  } else if (dir == RIGHT) {
    return sf::Vector2i{1, 0};
  }
  cout << "error \n";
  return sf::Vector2i{0, 0};
}

int entityState::vecDirToDir(sf::Vector2f vec) {
  if (vec.x == 0 and vec.y > 0) {
    return DOWN;
  } else if (vec.x == 0 and vec.y < 0) {
    return UP;
  } else if (vec.x < 0 and vec.y == 0) {
    return LEFT;
  } else if (vec.x > 0 and vec.y == 0) {
    return RIGHT;
  }

  return -1;
}

// strategy, if on one axis choose it, then if the currentDirection can be used
// to get closer to destination use it
//  else pick random axis between the two of destination (+/- x or +/- y)
int entityState::getAxisMoving(sf::Vector2f direction) {
  int testDir = vecDirToDir((sf::Vector2f)direction);
  // -1 if null vector or two axis involved
  if (testDir != -1) {
    return testDir;
  }

  sf::Vector2f produit_vec{0, 0};

  produit_vec.x = direction.x * dirToVecDir(currentDirection).x;
  produit_vec.y = direction.y * dirToVecDir(currentDirection).y;

  // mistake on the product, if produit_vec has a component = 1, it means both
  // dir have same directions
  // TODO : too complicated maybe simpler approach

  if (produit_vec.x > 0 || produit_vec.y > 0) {
    return currentDirection;
  }

  //Now we know direction and currentDirection are opposed for both x and y

  // last strategy random between the two axis
  if ((double)rand() / RAND_MAX > 0.5) {
    if (direction.x < 0) {
      return LEFT;
    }
    return RIGHT;
  }

  if (direction.y < 0) {
    return UP;
  }
  return DOWN;
}

void entityState::isMoving(int dir) {
  currentState = MOVING;
  if (dir != -1) {
    currentDirection = dir;
  }
}
