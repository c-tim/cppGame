#include <Human.hpp>
#include <gameManager.hpp>
#include <iostream>
#include <random>

using std::cout;

// TODO ask if good practice
#define gm gameManager

void gm::initialize_game() { gm::generatePNJs(GameDatas::spawned_pnj); }

// TODO, the random generator could have float value if we want to
int generate_random_number(int start, int end) {
  // TODO see this to understand
  std::random_device rd;  // obtain a random number from hardware
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(start, end);
  return distribution(gen);
}

void gm::generatePNJ() {
  float randPositionX = (float)generate_random_number(
      GameDatas::playableAreaX[0], GameDatas::playableAreaX[1]);
  float randPositionY = (float)generate_random_number(
      GameDatas::playableAreaY[0], GameDatas::playableAreaY[1]);

  std::unique_ptr<Human> ptrHuman = std::make_unique<Human>(
      idNextEntity, sf::Vector2f{randPositionX, randPositionY});
  cout << "spawned pnj : " << ptrHuman->to_string() << "\n";
  ++idNextEntity;
  spawned_entities.push_back(std::move(ptrHuman));
}

void gm::generatePNJs(int count) {
  for (int i = 0; i < count; i++) {
    generatePNJ();
  }
}

void gameManager::addEntity(Entity* entity) { cout << "remove this"; }