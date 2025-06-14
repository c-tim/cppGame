#include <Player.hpp>
#include <inputManager.hpp>
#include <gameManager.hpp>


void player::render( sf::RenderWindow &window) {
    //cout << "No render for Human";
    updateCooldowns();
    aSprite.setCurrentAnim(state.getIdAnim());
    aSprite.renderNextTickAnimation(window, feet_position);
    
};

void player::checkForBoundaries(){
  float offet = 0.1;
  if(feet_position.x <= GameDatas::playableAreaX[0]){
    feet_position.x = GameDatas::playableAreaX[0] + offet;
  }
    if(feet_position.x >= GameDatas::playableAreaX[1]){
    feet_position.x = GameDatas::playableAreaX[1]-offet;
  }
    if(feet_position.y <= GameDatas::playableAreaY[0]){
    feet_position.y = GameDatas::playableAreaY[0] + offet;
  }
    if(feet_position.y >= GameDatas::playableAreaY[1]){
    feet_position.y = GameDatas::playableAreaY[1]- offet;
  }


}

void player::move(){
    sf::Vector2i dir = getInputsKeyboard();
    if(dir == sf::Vector2i{0,0}){
      toIdle();
    }else{
      moveWithDir((sf::Vector2f)dir);
      checkForBoundaries();
    }
}


  bool player::canPlantCrop(){
    return tick_since_last_plant_crop>= cooldown_plant_crop;
  }
  void player::updateCooldowns(){
      tick_since_last_plant_crop += gameManager::deltaTimeMilli();
  }

    void player::resetCooldownPlantCrop(){
      tick_since_last_plant_crop=0;
    }



  void player::accept(defaultVisitor *vis) const {
  vis->visitPlayer(this);
}


void player::setPicked(bool picked){
  isPicked = picked;
}


