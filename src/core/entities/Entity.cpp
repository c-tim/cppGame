#include <Entity.hpp>
#include <ostream>


  /*std::ostream& Entity::operator<<(std::ostream& os){
        return os << type << " ("<<id<<",{"<<feet_position.x<<","<< feet_position.y <<"})\n";
  }*/


  std::string Entity::to_string(){
      return std::format("{} ({}, ({},{}))", type, id, feet_position.x, feet_position.y );
  }
