#include <gameManager.hpp>
#include <ressourcesLoader.hpp>

/// @brief 
void ressourceManager::initializeRessourcesGame() {
  humanAnimations.addAnimation("walkUp", "walkU", 1, 10000);
  humanAnimations.addAnimation("walkLeft", "walkL", 1, 10000);
  humanAnimations.addAnimation("walkDown", "walkD", 1, 10000);
  humanAnimations.addAnimation("walkRight", "walkR", 1, 10000);

  humanAnimations.addAnimation("walkUp", "walkU", 20, 50);
  humanAnimations.addAnimation("walkLeft", "walkL", 30, 100);
  humanAnimations.addAnimation("walkDown", "walkD", 20, 50);
  humanAnimations.addAnimation("walkRight", "walkR", 30, 100);

  patateAnimations.addAnimation("PatateCrops", "patateCrops", 8, 100);
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
 // MapLayer layerZero(map, 0, 5);
  //layerZero.update(gameManager::deltaTime());
  //window.draw(layerZero);
}