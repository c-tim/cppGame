initialize_game#pragma once

//#include <SFMLOrthogonalLayer.h>
#include "SFML/Graphics.hpp"
#include <animatedSprite.hpp>
#include <ostream>
#include <string>

#include "Entity.hpp"

class ressourceManager {

  private:

 public:
 //tmx::Map map;
  sf::Texture bgTexture;
    sf::Texture defaultSprite; //It should have worked without him, but guess the constructor of Sprite is not recognised

  sf::Sprite background;
  animatedSprite humanAnimations{0.6};
  animatedSprite patateAnimations{2.4};


  //Font used to display score
  sf::Font fontGame{"ressources/fonts/Pixellari.ttf"};
  void initializeRessourcesGame();
  void renderTilemap(sf::RenderWindow &window);
  void loadTextureFromFile(sf::Texture &t,const std::string& path);
  ressourceManager() :defaultSprite("ressources/texture/defaultSprite.png"), background{defaultSprite}
{
    initializeRessourcesGame();
  }
};