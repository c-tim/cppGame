#include <SFML/Window.hpp>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <inputManager.hpp>

using std::cout;




sf::Vector2i getInputsKeyboard(){
    sf::Vector2i dir{0,0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
        dir.x += 1;
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
        dir.x -= 1;
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
        dir.y += 1;
    }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        dir.y -= 1;
    }

   // cout<< " Inputs : "<< dir.x<< " / "<< dir.y<<"\n";
    return dir;
}

