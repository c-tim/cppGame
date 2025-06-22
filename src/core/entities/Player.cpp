#include <Player.hpp>
#include <gameManager.hpp>
#include <inputManager.hpp>
#include <entityState.hpp>

void player::render(sf::RenderWindow &window) {
  aSprite.setCurrentAnim(state.getIdAnim());
  aSprite.renderNextTickAnimation(window, feet_position);
};

/*Check if the player is in the playable area (if it is visible on the window)*/
void player::checkForBoundaries() {
  float offet = 0.1;
  if (feet_position.x <= GameDatas::playableAreaX[0]) {
    feet_position.x = GameDatas::playableAreaX[0] + offet;
  }
  if (feet_position.x >= GameDatas::playableAreaX[1]) {
    feet_position.x = GameDatas::playableAreaX[1] - offet;
  }
  if (feet_position.y <= GameDatas::playableAreaY[0]) {
    feet_position.y = GameDatas::playableAreaY[0] + offet;
  }
  if (feet_position.y >= GameDatas::playableAreaY[1]) {
    feet_position.y = GameDatas::playableAreaY[1] - offet;
  }
}

void player::move() {
  //not supposed to be here but I need to update it every tick (lack of time)
  tick_since_last_plant_crop += gameManager::deltaTime().asSeconds();

  sf::Vector2i dir = getInputsKeyboard(keyPlayer);
  if (dir == sf::Vector2i{0, 0} && state.getState()!= entityState::FLYING) {
    toIdle();
  } else {
    moveWithDir((sf::Vector2f)dir);
    checkForBoundaries();
  }
}


/* These 3 methods are useless now, I changed them with a global counter in entityManager (tick_since_lastPlant_grow)*/
bool player::canPlantCrop() {
  return keyPlayer.curent_cooldownPlant >= GameDatas::COOLDOWN_PLANT_TREE;
}
void player::updateCooldowns() {
  keyPlayer.curent_cooldownPlant += gameManager::deltaTimeMilli();
}

void player::resetCooldownPlantCrop() { keyPlayer.curent_cooldownPlant = 0; }


void player::accept(defaultVisitor *vis) const { vis->visitPlayer(this); }

void player::setPicked(bool picked) { isPicked = picked; }
