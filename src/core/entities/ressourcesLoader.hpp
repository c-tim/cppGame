#pragma once

#include <animatedSprite.hpp>
#include <ostream>

#include "Entity.hpp"

class ressourceManager {
 public:
  animatedSprite humanAnimations;

  void initializeRessourcesGame();

  ressourceManager(){
    initializeRessourcesGame();
  }
};