#include <crops.hpp>


using std::cout;

void crop::render(sf::RenderWindow &window) {
  // cout << "No render for Human";
  //aSprite.setCurrentAnim(0);
  aSprite.renderNextTickAnimation(window, feet_position);
};

void crop::move() {
  //cout<<"No purpose\n";
    //moveToDestination();
    //No Move
}
