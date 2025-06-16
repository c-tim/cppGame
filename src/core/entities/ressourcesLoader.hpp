#pragma once

//#include <SFMLOrthogonalLayer.h>

#include <animatedSprite.hpp>
#include <ostream>

#include "Entity.hpp"

class ressourceManager {
 public:
 // tmx::Map map;
  animatedSprite humanAnimations;
  animatedSprite patateAnimations{1};

  void initializeRessourcesGame();
  void renderTilemap(sf::RenderWindow &window);
  ressourceManager()  {
  //  map.load("ressources/tileMap/testTileMap.tmx");

    initializeRessourcesGame();
  }
};