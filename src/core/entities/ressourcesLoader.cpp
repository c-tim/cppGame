#include <gameManager.hpp>
#include <ressourcesLoader.hpp>
#include <gameDatas.hpp>

using std::cout, std::string;

/// @brief
void ressourceManager::initializeRessourcesGame() {

  /*We load the background texture*/
  loadTextureFromFile(bgTexture,"ressources/animation/mapGrassImagelbSprite.png");
  background.setTexture(bgTexture,true);
  background.setScale(sf::Vector2f(GameDatas::sizeBackgroundTileMap, GameDatas::sizeBackgroundTileMap));

/*We load in order the animations for humans*/
  humanAnimations.addAnimation("walkUp", "walkU", 1, 10000);
  humanAnimations.addAnimation("walkLeft", "walkL", 1, 10000);
  humanAnimations.addAnimation("walkDown", "walkD", 1, 10000);
  humanAnimations.addAnimation("walkRight", "walkR", 1, 10000);

  humanAnimations.addAnimation("walkUp", "walkU", 33, 50);
  humanAnimations.addAnimation("walkLeft", "walkL", 33, 50);
  humanAnimations.addAnimation("walkDown", "walkD", 33, 50);
  humanAnimations.addAnimation("walkRight", "walkR", 33, 50);

  /*same for crops but with loop = false*/
  patateAnimations.addAnimation("patateCrops", "patateCrops", 21, 2000);
  patateAnimations.animations[0].looped =false;
}

void ressourceManager::renderTilemap(sf::RenderWindow &window) {
  // TODO very uneffective to create each time but maplayer have to be
  // initialized and i need to get the map so i keep this for the moment
 /* MapLayer layerZero(map, 0);
  layerZero.update(gameManager::deltaTime());
  changeSizeLayerMap(GameDatas::sizeBackgroundTileMap, layerZero);*/
  window.draw(background);
}


void ressourceManager::loadTextureFromFile(sf::Texture &t,const string& path) {
  //string fullPath = "ressources/tileMap/testTileMap.png";
  if (!t.loadFromFile(path, false)) {
    cout << "Could not find " << path<<"\n";
  }
}