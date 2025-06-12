#include <SFML/Window.hpp>
#include <gameEvents.hpp>
#include <inputManager.hpp>
#include <iostream>

#include "SFML/Graphics.hpp"

#define sfkey sf::Keyboard

using std::cout;

sf::Vector2i getInputsKeyboard() {
  sf::Vector2i dir{0, 0};
  if (sfkey::isKeyPressed(sfkey::Key::Right)) {
    dir.x += 1;
  }
  if (sfkey::isKeyPressed(sfkey::Key::Left)) {
    dir.x -= 1;
  }
  if (sfkey::isKeyPressed(sfkey::Key::Down)) {
    dir.y += 1;
  }
  if (sfkey::isKeyPressed(sfkey::Key::Up)) {
    dir.y -= 1;
  }

  // cout<< " Inputs : "<< dir.x<< " / "<< dir.y<<"\n";
  return dir;
}

void getInputCrop(player &p) {
  if (sf::Keyboard::isKeyPressed(sfkey::Key::E)) {
    if (p.canPlantCrop()) {
      p.resetCooldownPlantCrop();
      gameManager::newCropPlanted(p.getPosition());
    }
  }
}

/*void checkIfHumanClicked(gameManager &gm){
  /*if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){

  }
}
*/