#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window{sf::VideoMode({300, 300}), "SFML works!"};

  // To use less CPU, we limit framerate to 30 fps
  // (On Michel Simatic's PC, under Windows, the execution of this code
  // drops down from 9% of CPU (without `window.setFramerateLimit(30);`)
  // to 0,2% de CPU (with `window.setFramerateLimit(30);`).
  // We could have preferred to `use window.setVerticalSyncEnabled(true);`
  // as mentionned in https://www.sfml-dev.org/tutorials/3.0/window/window/#playing-with-the-window
  // But, on Linux (WSL2) used by Michel Simatic, there is the error 
  // message "Setting vertical sync not supported" displayed by SFML: 
  // This message signifies that `window.setVerticalSyncEnabled(true);`
  // instruction cannot be considered on this Linux.
  // Note: With SFML v3.0.0 (and WSL2 Ubuntu 24.04 ?), message
  // "Setting vertical sync not supported" is still displayed with
  // `window.setFramerateLimit(30);`
  window.setFramerateLimit(30);
    
  sf::CircleShape shape(150.F);
  shape.setFillColor(sf::Color::Green);

  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    while (const std::optional event = window.pollEvent()) {
      // "close requested" event: we close the window
      if (event->is<sf::Event::Closed>())
        window.close();

      // Catch the resize events
      if (const auto *resized = event->getIf<sf::Event::Resized>()) {
        // Update the view to the new size of the window, so that contents is
        // not distorted by resizing See
        // https://www.sfml-dev.org/tutorials/3.0/graphics/view/#using-a-view
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
