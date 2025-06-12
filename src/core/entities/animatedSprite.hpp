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
    float ticksBetweenFrame;  // number of tick between each frame
    int numberFrame;
    bool looped = true;
  };
  sf::Texture timmy;
  sf::Sprite sprite;

  int currentTickWaited = 0;  // increment when called by
                              // renderNextTixkAnimation
  int currentFrame = 0;

  float scale;

  // a layer for the animt
  std::vector<struct animation> nullAnim;

  void nextFrameAnim();

 public:
  std::vector<struct animation> &animations;

  int currentAnim = 0;

  animatedSprite(animatedSprite &CopyAnim)
      : timmy("ressources/animation/walkLeft/walkL1.png"),
        sprite(timmy),
        animations{CopyAnim.animations},
        scale{CopyAnim.scale} {
    sprite.setScale(sf::Vector2f(CopyAnim.scale, CopyAnim.scale));
  }

  animatedSprite(float scale = 0.2f)
      : timmy("ressources/animation/walkLeft/walkL1.png"),
        sprite(timmy),
        animations{nullAnim},
        scale{scale} {
    sprite.setScale(sf::Vector2f(scale, scale));
  }

  void setCurrentAnim(int anim);

  void initialize();


  void renderNextTickAnimation(sf::RenderWindow &window);

  void renderNextTickAnimation(sf::RenderWindow &window, sf::Vector2f pos);

  void addAnimation(const std::string &path, const std::string &nameImage,
                    int numberImage, int speed = 1);

  // used to debug animantion
  void renderFrameOfAnimation(sf::RenderWindow &window, int animation,
                              int frame);
};