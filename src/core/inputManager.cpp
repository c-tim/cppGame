#include <SFML/Window.hpp>
#include <gameEvents.hpp>
#include <inputManager.hpp>
#include <iostream>
#include "SFML/Graphics.hpp"

#define sfkey sf::Keyboard

using std::cout;

int tickSinceLastClick = 0;
const int TRESHOLD_MAX_CLICK_DURATION =
    1000;  // if click longer than that forget it (allow the player to change its
          // mind)

sf::Vector2i getInputsKeyboard(struct player_info keys) {
  sf::Vector2i dir{0, 0};
  if (sfkey::isKeyPressed(keys.keyRight)) {
    dir.x += 1;
  }
  if (sfkey::isKeyPressed(keys.keyLeft)) {
    dir.x -= 1;
  }
  if (sfkey::isKeyPressed(keys.keyDown)) {
    dir.y += 1;
  }
  if (sfkey::isKeyPressed(keys.keyUp)) {
    dir.y -= 1;
  }

  // cout<< " Inputs : "<< dir.x<< " / "<< dir.y<<"\n";
  return dir;
}

bool getInputCrop(player &p) {
  if (sf::Keyboard::isKeyPressed(p.keyPlayer.keyPlant)) {
    gameManager::newCropPlanted(p.getPosition());
    return true;
    /*if (p.tick_since_last_plant_crop > GameDatas::COOLDOWN_PLANT_TREE) {
      p.tick_since_last_plant_crop=0;
    }*/
  }
  return false;
}

void checkDurationCLick(sf::RenderWindow &window, sf::Vector2f mousePos) {
  if (tickSinceLastClick <= TRESHOLD_MAX_CLICK_DURATION && tickSinceLastClick>0) {
    gameManager::OnMouseLeftClicked(mousePos);
  }
}

void checkIfHumanClicked(sf::RenderWindow &window) {
  sf::Vector2f rescaledMousePos =
      window.mapPixelToCoords(sf::Mouse::getPosition(window));


  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    // sf::Vector2f pos = sf::Mouse::getPosition();
    sf::CircleShape shape(50.F);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(rescaledMousePos);
    sf::CircleShape shape2(15.F);
    shape2.setFillColor(sf::Color::Blue);
    shape2.setPosition((sf::Vector2f)sf::Mouse::getPosition(window));
    window.draw(shape);
    window.draw(shape2);

    tickSinceLastClick+= gameManager::deltaTimeMilli();
  } else {
    checkDurationCLick(window, rescaledMousePos);
    tickSinceLastClick = 0;

    /*Debug shape*/
    sf::CircleShape shape(15.F);
    shape.setFillColor(sf::Color::Magenta);
    window.draw(shape);
    gameManager::movePlayerSelected(
        window.mapPixelToCoords(sf::Mouse::getPosition(window)));
    shape.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
    /*Debug shape*/
  }

//the right mouse is used to eliminate a character and the players
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
        gameManager::OnMouseRightClicked(rescaledMousePos);
    }
}

void gameManager::newPlayerBusted() {
  currentHidersBusted++;
  if (currentHidersBusted >= numberPlayer) {
    currentGameState = gameState::CantMove;
  }
}
