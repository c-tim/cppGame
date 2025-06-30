#pragma once

// #include <SFMLOrthogonalLayer.h>
#include <animatedSprite.hpp>
#include <ostream>
#include <string>

#include "Entity.hpp"
#include "SFML/Graphics.hpp"

enum class gameState;

class ressourceManager {
 private:
 public:
  // tmx::Map map;
  sf::Texture bgTexture;
  sf::Texture endTextureHidersWon, endTextureFinderWon;
  sf::Texture defaultSprite;  // It should have worked without him, but guess
                              // the constructor of Sprite is not recognised

  gameState currentGameStateRessourceLoaded = (gameState)-1;

  sf::Sprite background;
  sf::Sprite endImageSprite;

  animatedSprite introJeu{5};
  animatedSprite humanAnimations{0.6};
  animatedSprite patateAnimations{2.4};

  // Font used to display score
  sf::Font fontGame{"ressources/fonts/Pixellari.ttf"};

  // void initializeLoadingPanel();
  void initializeStartMenu();

  // is the ressources for the gameState have been loaded
  bool isCurrentRessourcesGameStateLoaded(gameState state_game);

  void ressourceGameLoopReady();
  void newRessourceStateAcquired(gameState newState);

  void initializeRessourcesGame();
  void renderStartGame(sf::RenderWindow &window);
  void renderTilemap(sf::RenderWindow &window);
  void loadTextureFromFile(sf::Texture &t, const std::string &path);
  void initializeEndMenu();
  void renderEndMenu(bool hidersWon, sf::RenderWindow &window);
  ressourceManager()
      : defaultSprite("ressources/texture/defaultSprite.png"),
        background{defaultSprite}, endImageSprite{defaultSprite}
 {
    // initializeRessourcesGame();
  }
};