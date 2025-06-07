#include <entityState.hpp>
#include <iostream>

using std::cout;

int entityState::getState() { return currentState; }

int entityState::changeIdAnim(int &varAnim) {
  // TODO when has correct animation return correct idAnim
  // varAnim= (currentState + 1) * currentDirection;
  // return varAnim;
  varAnim = 0;
  return 0;
}

void entityState::toIdle(int &varAnim, int dir) {
  currentState = IDLE;

  if (dir >= 0 && dir <= 3) {
    currentDirection = dir;
  }

  changeIdAnim(varAnim);
}

void entityState::moveDirection(sf::Vector2f normalized_dir, int &varAnim) {
  // the entity has to move in only one direction, no diagonals
  if (!((abs(normalized_dir.x) == 1 && normalized_dir.y == 0) ||
        (abs(normalized_dir.y) == 1 && normalized_dir.x == 0))) {
    cout
        << "Invalid normalized direction : the entity must move on one axis \n";
    return;
  }

  currentState = MOVING;
  if (normalized_dir.x == 1) {
    currentDirection = RIGHT;
  } else if (normalized_dir.x == -1) {
    currentDirection = LEFT;
  } else if (normalized_dir.y == 1) {
    currentDirection = DOWN;
  } else {
    currentDirection = UP;
  }

  changeIdAnim(varAnim);
}

sf::Vector2f entityState::dirToVecDir(int dir) {
  // TODO check if correct vector
  if (dir == UP) {
    return sf::Vector2f{0, -1};
  } else if (dir == LEFT) {
    return sf::Vector2f{-1, 0};
  } else if (dir == DOWN) {
    return sf::Vector2f{0, 1};
  }
  return sf::Vector2f{1, 0};
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
  int testDir = vecDirToDir(direction);
  // -1 if null vector or two axis involved
  if (testDir != -1) {
    return testDir;
  }

  sf::Vector2f produit_vec{0, 0};

  produit_vec.x = direction.x * dirToVecDir(currentDirection).x;
  produit_vec.y = direction.y * dirToVecDir(currentDirection).y;

//another test to see if now we have a direction (else the former direction is not compatible to reach destination)
  testDir = vecDirToDir(produit_vec);
  // -1 if null vector or two axis involved
  if (testDir != -1) {
    return testDir;
  }

  //last strategy random between the two axis
  if((double) rand()/RAND_MAX > 0.5) {
    if(direction.x<0){
      return LEFT;
    }
    return RIGHT;
  }

  if(direction.y<0){
    return UP;
  }
  return DOWN;
}
