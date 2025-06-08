#include <ressourcesLoader.hpp>

void ressourceManager::initializeRessourcesGame() {
  humanAnimations.addAnimation("walkUp", "walkU", 1, 10000);
  humanAnimations.addAnimation("walkLeft", "walkL", 1, 10000);
  humanAnimations.addAnimation("walkDown", "walkD", 1, 10000);
  humanAnimations.addAnimation("walkRight", "walkR", 1, 10000);

  humanAnimations.addAnimation("walkUp", "walkU", 30, 100);
  humanAnimations.addAnimation("walkLeft", "walkL", 30, 100);
  humanAnimations.addAnimation("walkDown", "walkD", 30, 100);
  humanAnimations.addAnimation("walkRight", "walkR", 30, 100);
}