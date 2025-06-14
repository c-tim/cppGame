#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>

// namespace for all unmodified datas
namespace GameDatas {
const int spawned_pnj = 200;

const std::vector<int> playableAreaX{20, 1870};
const std::vector<int> playableAreaY{90, 930};

const float humanSpeed = 0.08;
const float ratioMovePNJStart = 0.5;
const double ratioMovePNJGameLoop = 0.0001;
const double ratioIdlePNJGameLoop = 0.00001;



// window datas
struct windowsData {
  uint width;
  uint height;
};

const struct windowsData mainWindow{700, 500};

}  // namespace GameDatas