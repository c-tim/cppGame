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
    float speed; //number of tick between each frame
    int numberFrame;
    bool looped = true;
  };
  sf::Texture timmy;
  sf::Sprite sprite;

  int currentAnim=0;
  int currentTickWaited=0; //increment when called by renderNextTixkAnimation
  int currentFrame=0;

  // a layer for the animt
   std::vector<struct animation> animations;

    void nextFrameAnim();


 public:
  animatedSprite() : timmy("ressources/animation/walkLeft/walk1.png"), sprite(timmy){
    sprite.setScale(sf::Vector2f(0.2,0.2));
  }

  void setCurrentAnim(int anim);

  void initialize();

  void renderNextTickAnimation( sf::RenderWindow &window, sf::Vector2f pos);

  void addAnimation(const std::string &path, const std::string &nameImage,
                    int numberImage, int speed=1);

  // used to debug animantion
  void renderFrameOfAnimation(sf::RenderWindow &window, int animation,
                              int frame);
};