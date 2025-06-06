#pragma once
#include <myMain.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class animatedSprite {
 private:
  // an animatedSPrite has several animations, contained in the vector below
  struct animation {
    std::vector<sf::Texture> texture;
    int speed;
    int numberFrame;
  };
  sf::Texture timmy;
  sf::Sprite sprite;

  // a layer for the animt
  std::vector<struct animation> animations;

 public:
  animatedSprite() : timmy("ressources/animation/walkLeft/walk1.png"), sprite(timmy) {}



  void addAnimation(const std::string &path, const std::string &nameImage,
                    int numberImage);

  // used to debug animantion
  void renderFrameOfAnimation(sf::RenderWindow &window, int animation,
                              int frame);
};