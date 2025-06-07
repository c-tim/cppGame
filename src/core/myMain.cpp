
//written libraries
#include "myMain.h"
#include "gameManager.hpp"
#include <gameDatas.hpp>
#include <animatedSprite.hpp>
#include <ressourcesLoader.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>

#define gData GameDatas


using namespace std;

  //set a static reference to gameManagerInstance, callable by everyone (TODO may be bad practice)
/*namespace gameEvent{
    gameManager game_manager{resManager};
}*/




int myMain() {
  // Creating the window
  sf::RenderWindow window{sf::VideoMode({gData::mainWindow.width, gData::mainWindow.height}),
                          "SFML works!"};

  window.setFramerateLimit(30);
  

  ressourceManager resManager;
  gameManager game_manager{resManager};

  sf::CircleShape shape(150.F);
  shape.setFillColor(sf::Color::Green);

  sf::Texture testTexture("ressources/animation/walkLeft/walk1.png");
  sf::Sprite testSprite(testTexture);

  animatedSprite testAnimated{};
  testAnimated.addAnimation("walkLeft","walk",33);

  game_manager.initialize_game(); //TODO merge all behaviours for lisibility

  

  //instance_game_manager.generatePNJs


  int temp_i = 0;
  while (window.isOpen()) {
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
    cout<<game_manager.deltaTime()<<"\n";
    window.clear();
    window.draw(shape);
   // window.draw(testSprite);
   game_manager.renderEntities(window);
   testAnimated.renderFrameOfAnimation(window, 0, temp_i);
    window.display();
  }


return 0;
}


