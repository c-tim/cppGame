#include <gameManager.hpp>
#include <ressourcesLoader.hpp>
#include <gameDatas.hpp>

using std::cout, std::string;

/// @brief
void ressourceManager::initializeRessourcesGame() {
  loadTextureFromFile(bgTexture,"ressources/animation/mapGrassImagelbSprite.png");
  background.setTexture(bgTexture,true);
  //background.setPosition({10,10});
  background.setScale(sf::Vector2f(GameDatas::sizeBackgroundTileMap, GameDatas::sizeBackgroundTileMap));
   /*float gneuh = 500;
    background.setOrigin(sf::Vector2f(background.getGlobalBounds().size.x/2,background.getGlobalBounds().size.y/2));
    background.setScale(sf::Vector2f(gneuh,gneuh));
    background.setPosition({0,0});*/

  humanAnimations.addAnimation("walkUp", "walkU", 1, 10000);
  humanAnimations.addAnimation("walkLeft", "walkL", 1, 10000);
  humanAnimations.addAnimation("walkDown", "walkD", 1, 10000);
  humanAnimations.addAnimation("walkRight", "walkR", 1, 10000);

  humanAnimations.addAnimation("walkUp", "walkU", 33, 50);
  humanAnimations.addAnimation("walkLeft", "walkL", 33, 50);
  humanAnimations.addAnimation("walkDown", "walkD", 33, 50);
  humanAnimations.addAnimation("walkRight", "walkR", 33, 50);

  patateAnimations.addAnimation("patateCrops", "patateCrops", 21, 2000);
  patateAnimations.animations[0].looped =false;
  /*patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);*/
}

void ressourceManager::renderTilemap(sf::RenderWindow &window) {
  // TODO very uneffective to create each time but maplayer have to be
  // initialized and i need to get the map so i keep this for the moment
 /* MapLayer layerZero(map, 0);
  layerZero.update(gameManager::deltaTime());
  changeSizeLayerMap(GameDatas::sizeBackgroundTileMap, layerZero);*/
  window.draw(background);
}

/*void ressourceManager::changeSizeLayerMap(float scale, MapLayer &layer) {
  for (size_t y = 0; y < GameDatas::dimensionsBackground.y; ++y) {
    for (size_t x = 0; x < GameDatas::dimensionsBackground.x; ++x) {
      cout << "okay go for " << y << "/" << x << "\n";
      unsigned int tileID = layer.getTile(x, y).ID;
      if (tileID > 0) {
        float scaledX = x * scale;
        float scaledY = y * scale;
      }
    }
  }
}*/

void ressourceManager::loadTextureFromFile(sf::Texture &t,const string& path) {
  //string fullPath = "ressources/tileMap/testTileMap.png";
  if (!t.loadFromFile(path, false)) {
    cout << "Could not find " << path<<"\n";
  }
}