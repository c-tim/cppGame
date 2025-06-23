#include <math.h>

#include <Entity.hpp>
#include <gameManager.hpp>
#include <ostream>

using std::cout;

std::string Entity::to_string() {
  return std::format("{} ({}, ({},{}))", type, id, feet_position.x,
                     feet_position.y);
}

void Entity::setDestination(sf::Vector2f dest) {
  destination = dest;
  has_destination = true;
  state.isMoving(state.vecDirToDir(dest - feet_position));
}

// TODO find the real function to square
double square(float a) { return a * a; }

double distance(sf::Vector2f a, sf::Vector2f b) {
  double result = (square(a.x - b.x) + square(a.y - b.y));
  return sqrt(result);
}

sf::Vector2f vectorialProduct(sf::Vector2f a, sf::Vector2f b) {
  return sf::Vector2f{a.x * b.x, a.y * b.y};
}

/*If there is still distance between entity and destination, set the direction,
 * otherwise, go to state Idle*/
void Entity::moveToDestination() {
  sf::Vector2f direction = getDirectionFromDestination();

  if (direction == sf::Vector2f{0, 0}) {
    state.toIdle();
    has_destination = false;
    return;
  }
  moveWithDir(direction);
}
void Entity::toIdle(entityState::s_direction dir) { state.toIdle(dir); }

bool Entity::isMoving() { return state.getState() == 1; }

sf::Vector2f Entity::getPosition() { return feet_position; }

void Entity::setPosition(sf::Vector2f pos) { feet_position = pos; }

bool Entity::canHaveNewDestination() { return state.getState() == 0; }

sf::Vector2f Entity::getDirectionFromDestination() {
  // TODO here to implement blocking move
  if (state.getState() == 0) {
    return sf::Vector2f{0, 0};
  }

  sf::Vector2f direction = destination - feet_position;
  return direction;
}

/*Move the player according to the given direction*/
void Entity::moveWithDir(sf::Vector2f direction) {
  sf::Vector2i normalized_direction_to_take =
      state.dirToVecDir(state.getAxisMoving(direction));
  state.moveDirection(normalized_direction_to_take);

  // we get the distance between pos and destination projected on the axis used
  // to move
  float distanceToDestinationProjectedOnAxis =
      distance(vectorialProduct((sf::Vector2f)normalized_direction_to_take,
                                feet_position),
               vectorialProduct((sf::Vector2f)normalized_direction_to_take,
                                destination));

  // speed adapted to the tick speed
  float stepToMove = speed * gameManager::deltaTimeMilli();

  // if the entity will move further than necessary, we reduce the step
  if (distanceToDestinationProjectedOnAxis <= stepToMove) {
    stepToMove = distanceToDestinationProjectedOnAxis;
  }

  feet_position.x += normalized_direction_to_take.x * stepToMove;
  feet_position.y += normalized_direction_to_take.y * stepToMove;
}

/* Used to check if mouse is on the sprite*/
bool Entity::isSpriteInBoundOfPos(sf::Vector2f pos) const {
  return aSprite.getSprite().getGlobalBounds().contains(pos);
}
