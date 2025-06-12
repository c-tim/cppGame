#include <Player.hpp>
#include <inputManager.hpp>
#include <gameManager.hpp>


void player::render( sf::RenderWindow &window) {
    //cout << "No render for Human";
    updateCooldowns();
    aSprite.setCurrentAnim(state.getIdAnim());
    aSprite.renderNextTickAnimation(window, feet_position);
    
};


void player::move(){
    sf::Vector2i dir = getInputsKeyboard();
    if(dir == sf::Vector2i{0,0}){
      toIdle();
    }else{
      moveWithDir((sf::Vector2f)dir);
    }
}


  bool player::canPlantCrop(){
    return tick_since_last_plant_crop>= cooldown_plant_crop;
  }
  void player::updateCooldowns(){
      tick_since_last_plant_crop += gameManager::deltaTime();
  }

    void player::resetCooldownPlantCrop(){
      tick_since_last_plant_crop=0;
    }



  void player::accept(defaultVisitor *vis) const {
  vis->visitPlayer(this);
}



