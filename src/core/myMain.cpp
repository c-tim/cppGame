
#include "myMain.h"
#include "gameManager.hpp"
#include <gameDatas.hpp>
#include <animatedSprite.hpp>
#include <ressourcesLoader.hpp>
#include <coucouVisitor.hpp>


#include <SFML/Graphics.hpp>
#include <iostream>

#include "imgui-SFML.h"  // for ImGui::SFML::* functions and SFML-specific overloads
#include "imgui.h"

#define gData GameDatas


using namespace std;




int myMain() {
  // Creating the window
  sf::RenderWindow window{sf::VideoMode({gData::mainWindow.width, gData::mainWindow.height}),
                          "SFML works!"};

  window.setFramerateLimit(30);
  


  gameManager game_manager{};


  sf::CircleShape shape(150.F);
  shape.setFillColor(sf::Color::Green);


  game_manager.initialize_game(); //TODO merge all behaviours for lisibility

  game_manager.callEntityManagerFaitLAppel();

  int temp_i = 0;
  while (window.isOpen() && game_manager.currentGameState == gameState::InGame) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) window.close();

      //TODO implement choixe between resizable and not resizable
      if (const auto *resized = event->getIf<sf::Event::Resized>()) {

        sf::FloatRect visibleArea({0.f, 0.f}, sf::Vector2f(resized->size));

        window.setView(sf::View(visibleArea));        
      }
      
    }
    ++temp_i;
    if(temp_i > 30){
      temp_i = 0;
    }
    gameManager::setDeltaTime();
    window.clear();
   game_manager.applyGameLoopAndRender(window);
    window.display();
  }


return 0;
}


