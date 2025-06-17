#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

// namespace for all unmodified datas
namespace GameDatas {
const int spawned_pnj = 10;

const std::vector<int> playableAreaX{20, 1870};
const std::vector<int> playableAreaY{90, 930};

const int number_players = 2;

const float humanSize = 5;

const float humanSpeed = 0.08;
const float cropSpeed = 0.0001;

const int COOLDOWN_PLANT_TREE = 5000;

const float ratioMovePNJStart = 0.7;
const double ratioMovePNJGameLoop = 0.01;
const double ratioIdlePNJGameLoop = 0.0001;


const float sizeBackgroundTileMap = 4;
const sf::Vector2i dimensionsBackground{20,10};

// window datas
struct windowsData {
  uint width;
  uint height;
};

const struct windowsData mainWindow{700, 500};

}  // namespace GameDatas