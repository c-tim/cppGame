#include <crops.hpp>

using std::cout;

void crop::render(sf::RenderWindow &window) {
  aSprite.setCurrentAnim(0);
  aSprite.renderNextTickAnimation(window, false);

/*  if (aSprite.animations[aSprite.currentAnim].ticksBetweenFrame <=
      aSprite.currentTickWaited) {
    aSprite.currentTickWaited = 0;
    aSprite.nextFrameAnim();
  }*/
}



void crop::move() {
  // cout<<"No purpose\n";
  // moveToDestination();
  // No Move
}
