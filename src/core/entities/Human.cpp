#include <Human.hpp>

using std::cout;

void Human::render( sf::RenderWindow &window) {
    //cout << "No render for Human";
    aSprite.renderNextTickAnimation(window, feet_position);
    
};


