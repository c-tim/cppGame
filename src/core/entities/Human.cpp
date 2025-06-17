#include <Human.hpp>

using std::cout;

void Human::render(sf::RenderWindow &window) {
  aSprite.setCurrentAnim(state.getIdAnim());
  aSprite.renderNextTickAnimation(window, feet_position);
};

void Human::move() {
    moveToDestination();
}

void Human::accept(defaultVisitor *vis) const {
  vis->visitHuman(this);
}

void Human::setPicked(bool picked){
  isPicked = picked;
}