
//written libraries
#include "myMain.h"
#include "gameManager.hpp"
#include <gameDatas.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>

#define gData GameDatas


using namespace std;

  //set a static reference to gameManagerInstance, callable by everyone (TODO may be bad practice)
namespace gameEvent{
    gameManager game_manager{};
}




int myMain() {
  // Creating the window
  sf::RenderWindow window{sf::VideoMode({gData::mainWindow.width, gData::mainWindow.height}),
                          "SFML works!"};

  window.setFramerateLimit(30);

  sf::CircleShape shape(150.F);
  shape.setFillColor(sf::Color::Green);

  gameEvent::game_manager.initialize_game(); //TODO merge all behaviours for lisibility

  

  //instance_game_manager.generatePNJs


  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) window.close();

      //TODO implement choixe between resizable and not resizable
      if (const auto *resized = event->getIf<sf::Event::Resized>()) {

        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));
        window.setView(sf::View(visibleArea));
      }
      
    }
    window.clear();
    window.draw(shape);
    window.display();
  }


return 0;
}


