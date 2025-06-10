#include <entityState.hpp>
#include <iostream>

using std::cout;

int entityState::getState() { return currentState; }

int entityState::getIdAnim() { return (4 * currentState + currentDirection); }

int entityState::changeIdAnim(animatedSprite &varAnim) {
  // TODO when has correct animation return correct idAnim
  // varAnim= (currentState + 1) * currentDirection;
  // return varAnim;
  varAnim.setCurrentAnim(4 * currentState + currentDirection);
  return 0;
}

void entityState::setCurrentDirection(int dir, animatedSprite &varAnim) {
  currentDirection = dir;
  changeIdAnim(varAnim);
}

void entityState::toIdle(animatedSprite &varAnim, int dir) {
  currentState = IDLE;

  if (dir >= 0 && dir <= 3) {
    currentDirection = dir;
  }

  changeIdAnim(varAnim);
}

void entityState::moveDirection(sf::Vector2i normalized_dir,
                                animatedSprite &varAnim) {
  // the entity has to move in only one direction, no diagonals
  if (!((abs(normalized_dir.x) == 1 && normalized_dir.y == 0) ||
        (abs(normalized_dir.y) == 1 && normalized_dir.x == 0))) {
    cout
        << "Invalid normalized direction : the entity must move on one axis \n";
    return;
  }

  currentState = MOVING;
  currentDirection = vecDirToDir((sf::Vector2f) normalized_dir);

  /*if(currentDirection != RIGHT){
      //cout<<"ha";

    }else{
      //cout<<"hb";
    }*/
  /*if (normalized_dir.x == 1) {
    currentDirection = RIGHT;
  } else if (normalized_dir.x == -1) {
    currentDirection = LEFT;
  } else if (normalized_dir.y == 1) {
    currentDirection = DOWN;
  } else {
    currentDirection = UP;
  }*/

  changeIdAnim(varAnim);
}

sf::Vector2i entityState::dirToVecDir(int dir) {
  // TODO check if correct vector
  if (dir == UP) {
    return sf::Vector2i{0, -1};
  } else if (dir == LEFT) {
    return sf::Vector2i{-1, 0};
  } else if (dir == DOWN) {
    return sf::Vector2i{0, 1};
  }
  return sf::Vector2i{1, 0};
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
  int testDir = vecDirToDir((sf::Vector2f) direction);
  // -1 if null vector or two axis involved
  if (testDir != -1) {
    //   setCurrentDirection(testDir, varAnim);
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

  /*if (produit_vec.x == 1) {
    produit_vec.x = direction.x / abs(direction.x);
  } else {
    produit_vec.x = 0;
  }

  if (produit_vec.y == 1) {
    produit_vec.y = direction.y / abs(direction.y);
  } else {
    produit_vec.y = 0;
  }*/

  // another test to see if now we have a direction (else the former direction
  // is not compatible to reach destination)
  testDir = vecDirToDir((sf::Vector2f) produit_vec);
  // -1 if null vector or two axis involved
  if (testDir != -1) {
    //setCurrentDirection(testDir, varAnim);
    return testDir;
  }

  // last strategy random between the two axis
  if ((double)rand() / RAND_MAX > 0.5) {
    if (direction.x < 0) {
      // setCurrentDirection(LEFT, varAnim);
      return LEFT;
    }
    // setCurrentDirection(RIGHT, varAnim);

    return RIGHT;
  }

  if (direction.y < 0) {
    // setCurrentDirection(UP, varAnim);

    return UP;
  }
  // setCurrentDirection(DOWN, varAnim);

  return DOWN;
}

void entityState::isMoving(int dir) {
  currentState = MOVING;
  if (dir != -1) {
    currentDirection = dir;
  }
}
