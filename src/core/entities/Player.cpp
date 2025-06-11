#include <Player.hpp>
#include <inputManager.hpp>


void player::render( sf::RenderWindow &window) {
    //cout << "No render for Human";
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



