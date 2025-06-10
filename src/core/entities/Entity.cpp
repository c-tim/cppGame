#include <math.h>

#include <Entity.hpp>
#include <gameManager.hpp>
#include <ostream>

using std::cout;

/*std::ostream& Entity::operator<<(std::ostream& os){
      return os << type << " ("<<id<<",{"<<feet_position.x<<","<<
feet_position.y <<"})\n";
}*/

std::string Entity::to_string() {
  return std::format("{} ({}, ({},{}))", type, id, feet_position.x,
                     feet_position.y);
}

void Entity::setDestination(sf::Vector2f dest) {
  destination = dest;
  has_destination = true;
  // state.moveDirection(sf::Vector2f{0, 0}, aSprite);
  cout << "ID : " << id << " : destination set " << destination.x << "/"
       << destination.y << "\n";
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

void Entity::moveToDestination() {

sf::Vector2f direction = getDirectionFromDestination();

  if (direction == sf::Vector2f{0, 0}) {
    state.toIdle(aSprite);
    has_destination = false;
    return;
  }

  // cout<<"distanceToObjective "<<std::to_string(distance(feet_position,
  // destination)) << "\n";

  sf::Vector2i normalized_direction_to_take =
      state.dirToVecDir(state.getAxisMoving( direction));

      moveWithDir(normalized_direction_to_take);

}
void Entity::toIdle(int dir) { state.toIdle(aSprite, dir); }

bool Entity::isMoving() { return state.getState() == 1; }

sf::Vector2f Entity::getPosition() { return feet_position; }

bool Entity::canHaveNewDestination() { return state.getState() == 0; }

sf::Vector2f Entity::getDirectionFromDestination() {

    // TODO here to implement blocking move
  if (state.getState() == 0) {
    return sf::Vector2f{0,0};
  }

  sf::Vector2f direction = destination - feet_position;

  if (abs(direction.x) < 5 || std::isnan(direction.x)) {
    direction.x = 0;
  }

  if (abs(direction.y) < 5 || std::isnan(direction.y)) {
    direction.y = 0;
  }
  return direction;
}

void Entity::moveWithDir(sf::Vector2i normalized_direction_to_take) {


    state.moveDirection(normalized_direction_to_take, aSprite);
  /*cout << "ID : " << id << " : position: " << feet_position.x << "/"
       << feet_position.y << "\n";

  cout << "ID : " << id << " : destination to go : " << destination.x << "/"
       << destination.y << "\n";
  cout << "ID : " << id
       << " : direction to go : " << normalized_direction_to_take.x << "/"
       << normalized_direction_to_take.y << "\n";
*/
  // we get the distance between pos and destination projected on the axis used
  // to move
  float distanceToDestinationProjectedOnAxis =
      distance(vectorialProduct((sf::Vector2f) normalized_direction_to_take, feet_position),
               vectorialProduct((sf::Vector2f) normalized_direction_to_take, destination));

  // speed adapted to the tick speed
  float stepToMove = speed * gameManager::deltaTime();

  // if the entity will move further than necessary, we reduce the step
  if (distanceToDestinationProjectedOnAxis <= stepToMove) {
    stepToMove = distanceToDestinationProjectedOnAxis;
  }

  feet_position.x += normalized_direction_to_take.x * stepToMove;
  feet_position.y += normalized_direction_to_take.y * stepToMove;

  // if(abs(destination.x - feet_position.x)> )

  // cout<< "ID : " << id <<" moving to "<<
  // destination.x<<"/"<<destination.y<<"\n";
}