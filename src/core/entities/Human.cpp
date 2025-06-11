#include <Human.hpp>

using std::cout;

void Human::render(sf::RenderWindow &window) {
  // cout << "No render for Human";
  aSprite.setCurrentAnim(state.getIdAnim());
  aSprite.renderNextTickAnimation(window, feet_position);
};

void Human::move() {
    moveToDestination();
}
