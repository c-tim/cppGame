/* Adaptation of
   https://github.com/fallahn/tmxlite/blob/master/SFML3Example/SFMLExample/src/main.cpp :
    - #include "SFMLOrthogonalLayer.hpp"
      becomes
      #include "SFMLOrthogonalLayer.h"
    - int main()
      becomes
      int myMain()
    - map.load("assets/demo.tmx");
      becomes
      map.load("res/demo.tmx");
    - Adaptations to compile correctly woth SFML 3.0.1
*/
/*********************************************************************
(c) Matt Marchant & contributors 2016 - 2024
http://trederia.blogspot.com

tmxlite - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/


#include "SFMLOrthogonalLayer.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>


int myMain()
{
  sf::RenderWindow window{sf::VideoMode({800, 600}), "SFML window"};

    tmx::Map map;
    map.load("res/demo.tmx");

    MapLayer layerZero(map, 0);
    MapLayer layerOne(map, 1);
    MapLayer layerTwo(map, 2);

    sf::Clock globalClock;
    sf::Clock wiggleClock;

    bool doWiggle = false;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            else if(const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                switch(keyPressed->code)
                {
		case sf::Keyboard::Key::W:
                        // toggle doWiggle
                        doWiggle = !doWiggle;
                    break;
                }
            }
        }


        sf::Time duration = globalClock.restart();
        layerZero.update(duration);

        sf::Vector2f newOffset = sf::Vector2f(0.f, 0.f);
        if (doWiggle)
        {
             newOffset = sf::Vector2f(std::cos(wiggleClock.getElapsedTime().asSeconds()) * 100.f, 0.f);
        }
        layerZero.setOffset(newOffset);
        layerOne.setOffset(newOffset);
        layerTwo.setOffset(newOffset);

        window.clear(sf::Color::Black);
        window.draw(layerZero);
        window.draw(layerOne);
        window.draw(layerTwo);
        window.display();
    }

    return 0;
}
