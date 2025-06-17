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
    float adjustScale = 1; 
  };
  sf::Texture timmy;
  sf::Sprite sprite;

  int currentFrame = 0;

  float scale;

  // a layer for the animt
  std::vector<struct animation> nullAnim;

 public:
  int currentTickWaited = 0;  // increment when called by
                              // renderNextTixkAnimation
  void nextFrameAnim();
  std::vector<struct animation> &animations;

  int currentAnim = 0;

  animatedSprite(animatedSprite &CopyAnim)
      : timmy("ressources/animation/walkLeft/walkL1.png"),
        sprite(timmy),
        animations{CopyAnim.animations},
        scale{CopyAnim.scale} {
    sprite.setScale(sf::Vector2f(scale, scale));
  }

  animatedSprite(float scale = 0.2)
      : timmy("ressources/animation/walkLeft/walkL1.png"),
        sprite(timmy),
        animations{nullAnim},
        scale{scale} {
    //sprite.setScale(sf::Vector2f(scale, scale));
    
  }

  void setCurrentAnim(int anim);

  void initialize();

  void renderNextTickAnimation(sf::RenderWindow &window,
                               bool canSkipFrame = true);

  void renderNextTickAnimation(sf::RenderWindow &window, sf::Vector2f pos,
                               bool canSkipFrame = true);

  void addAnimation(const std::string &path, const std::string &nameImage,
                    int numberImage, int speed = 1, float scale = 1);

  // used to debug animantion
  void renderFrameOfAnimation(sf::RenderWindow &window, int animation,
                              int frame);

  sf::Sprite getSprite() const;

  void setTexture(sf::Texture &t);

  void spriteSetScale(float x, float y);

 // void fixTextureArtefact(sf::Texture &t);
};