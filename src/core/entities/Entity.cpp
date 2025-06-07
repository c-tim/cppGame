#include <Entity.hpp>
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
}

void Entity::moveToDestination(){
  cout<<" moving to "<< destination.x<<"/"<<destination.y<<"\n";
}