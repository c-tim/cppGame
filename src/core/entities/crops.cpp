#include <crops.hpp>

using std::cout;

void crop::render(sf::RenderWindow &window) {
  aSprite.setCurrentAnim(0);
  //TODO I already set the scale but i dont understand why i doesnt work with these so i set here
  //aSprite.spriteSetScale(400,400);
  aSprite.renderNextTickAnimation(window, feet_position,false);

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

void crop::accept(defaultVisitor *vis) const {
  vis->visitCrop(this);
}

