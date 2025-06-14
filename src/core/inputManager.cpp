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

void checkIfHumanClicked(sf::RenderWindow &window) {
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    // sf::Vector2f pos = sf::Mouse::getPosition();
    gameManager::OnMouseClicked(
        window.mapPixelToCoords(sf::Mouse::getPosition()));
    sf::CircleShape shape(15.F);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition()));
    sf::CircleShape shape2(15.F);
    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition((sf::Vector2f)sf::Mouse::getPosition());
    window.draw(shape);
    window.draw(shape2);
  } else {
    sf::CircleShape shape(15.F);
    shape.setFillColor(sf::Color::Magenta);

    gameManager::movePlayerSelected(
    window.mapPixelToCoords(sf::Mouse::getPosition()));
    shape.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition()));
    window.draw(shape);
  }
}

void gameManager::newPlayerBusted() {
  currentHidersBusted++;
  if (currentHidersBusted >= numberHiders) {
    currentGameState = gameState::CantMove;
  }
}
