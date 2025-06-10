#include <Player.hpp>


void player::render( sf::RenderWindow &window) {
    //cout << "No render for Human";
    aSprite.setCurrentAnim(state.getIdAnim());
    aSprite.renderNextTickAnimation(window, feet_position);
    
};





