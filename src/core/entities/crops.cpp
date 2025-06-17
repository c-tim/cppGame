#include <crops.hpp>

using std::cout;

void crop::render(sf::RenderWindow &window) {
  aSprite.setCurrentAnim(0);
  aSprite.renderNextTickAnimation(window, feet_position,false);
}



void crop::move() {
  // cout<<"No purpose\n";
  // moveToDestination();
  // No Move
}

void crop::accept(defaultVisitor *vis) const {
  vis->visitCrop(this);
}

