#include "myMain.h"

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

// window datas
struct windowsData {
  int width;
  int height;

};

const struct windowsData mainWindow{700, 500};

int myMain() {
  // Creating the window
  sf::RenderWindow window{sf::VideoMode({mainWindow.width, mainWindow.height}),
                          "SFML works!"};

  window.setFramerateLimit(30);

  sf::CircleShape shape(150.F);
  shape.setFillColor(sf::Color::Green);


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


