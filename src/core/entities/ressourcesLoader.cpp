#include <gameDatas.hpp>
#include <gameManager.hpp>
#include <ressourcesLoader.hpp>

using std::cout, std::string;

void ressourceManager::initializeStartMenu() {
  introJeu.addAnimation("introJeu", "intro", 20, 150);
  newRessourceStateAcquired(gameState::StartMenu);
}

/// @brief
void ressourceManager::initializeRessourcesGame() {
  /*We load the background texture*/
  loadTextureFromFile(bgTexture,
                      "ressources/animation/mapGrassImagelbSprite.png");
  background.setTexture(bgTexture, true);
  background.setScale(sf::Vector2f(GameDatas::sizeBackgroundTileMap,
                                   GameDatas::sizeBackgroundTileMap));

  /*We load in order the animations for humans*/
  humanAnimations.addAnimation("walkUp", "walkU", 1, 10000);
  humanAnimations.addAnimation("walkLeft", "walkL", 1, 10000);
  humanAnimations.addAnimation("walkDown", "walkD", 1, 10000);
  humanAnimations.addAnimation("walkRight", "walkR", 1, 10000);

  humanAnimations.addAnimation("walkUp", "walkU", 33, 50);
  humanAnimations.addAnimation("walkLeft", "walkL", 33, 50);
  humanAnimations.addAnimation("walkDown", "walkD", 33, 50);
  humanAnimations.addAnimation("walkRight", "walkR", 33, 50);

  humanAnimations.addAnimation("flying", "flying", 37, 30);
  humanAnimations.animations[8].adjustScale = 1.4;

  /*same for crops but with loop = false*/
  patateAnimations.addAnimation("patateCrops", "patateCrops", 21, 2000);
  patateAnimations.animations[0].looped = false;
}

void ressourceManager::ressourceGameLoopReady() {
  newRessourceStateAcquired(gameState::InGame);
}

void ressourceManager::renderTilemap(sf::RenderWindow &window) {
  // TODO very uneffective to create each time but maplayer have to be
  // initialized and i need to get the map so i keep this for the moment
  /* MapLayer layerZero(map, 0);
   layerZero.update(gameManager::deltaTime());
   changeSizeLayerMap(GameDatas::sizeBackgroundTileMap, layerZero);*/
  window.draw(background);
}

void ressourceManager::renderStartGame(sf::RenderWindow &window) {
  if (isCurrentRessourcesGameStateLoaded(gameState::StartMenu)) {
    introJeu.renderNextTickAnimation(window, sf::Vector2f{1000, 500});
  }
}

void ressourceManager::loadTextureFromFile(sf::Texture &t, const string &path) {
  // string fullPath = "ressources/tileMap/testTileMap.png";
  if (!t.loadFromFile(path, false)) {
    cout << "Could not find " << path << "\n";
  }
}

bool ressourceManager::isCurrentRessourcesGameStateLoaded(
    gameState state_game_manager) {
  return (int)currentGameStateRessourceLoaded >= (int)state_game_manager;
}

void ressourceManager::newRessourceStateAcquired(gameState newState) {
  if ((int)newState < (int)currentGameStateRessourceLoaded) {
    cout << "ERROR ressources loaded in the wrong order\n";
    assert(1 == 0);
  }
  if ((int)newState == (int)currentGameStateRessourceLoaded) {
    cout << "ERROR ressources loaded twice\n";
    assert(1 == 0);
  }

  currentGameStateRessourceLoaded = newState;
}

void ressourceManager::initializeEndMenu() {
  loadTextureFromFile(endTextureHidersWon, "ressources/texture/assiette.png");

  loadTextureFromFile(endTextureFinderWon,
                      "ressources/texture/humanPrison.png");

  newRessourceStateAcquired(gameState::ENDGAME);
}

void ressourceManager::renderEndMenu(bool hidersWon, sf::RenderWindow &window) {
  if (hidersWon) {
    endImageSprite.setTexture(endTextureHidersWon, true);
    endImageSprite.setScale({20, 20});

  } else {
    endImageSprite.setTexture(endTextureFinderWon, true);
    endImageSprite.setScale({8, 8});
  }

  window.draw(endImageSprite);
}