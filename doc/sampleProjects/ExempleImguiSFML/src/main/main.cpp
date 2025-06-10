//
// This code is a copy-paste from
// https://github.com/SFML/imgui-sfml/blob/master/examples/minimal/main.cpp
//

#include <SFML/Graphics.hpp>

#include "imgui-SFML.h"  // for ImGui::SFML::* functions and SFML-specific overloads
#include "imgui.h"  // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h

int main() {
  sf::RenderWindow window(sf::VideoMode({1000, 700}), "ImGui + SFML = <3");
  window.setFramerateLimit(60);
  if (!ImGui::SFML::Init(window)) return -1;

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  sf::Clock deltaClock;
  while (window.isOpen()) {
    while (const auto event = window.pollEvent()) {
      ImGui::SFML::ProcessEvent(window, *event);

      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    ImGui::SFML::Update(window, deltaClock.restart());

    ImGui::ShowDemoWindow();

    ImGui::Begin("Hello, world!");
    ImGui::Button("Look at this pretty button");
    ImGui::End();

    window.clear();
    window.draw(shape);
    ImGui::SFML::Render(window);
    window.display();
  }

  ImGui::SFML::Shutdown();
}
