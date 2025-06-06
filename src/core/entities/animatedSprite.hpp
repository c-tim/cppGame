#pragma once
#include <myMain.h>

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class animatedSprite {

private:

struct animation{
std::vector<sf::Texture> texture;
int speed;
};

// a layer for the animt
std::vector<struct animation> animations;

public :
animatedSprite(){

}

void addAnimation(std::string &path);


};