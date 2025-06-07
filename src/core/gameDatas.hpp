#pragma once

// namespace for all unmodified datas
namespace GameDatas {
const int spawned_pnj = 20;

const std::vector<int> playableAreaX{100, 600};
const std::vector<int> playableAreaY{100, 400};


// window datas
struct windowsData {
  uint width;
  uint height;
};

const struct windowsData mainWindow{700, 500};

}  // namespace GameDatas