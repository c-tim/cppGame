#include <Human.hpp>
#include <entityManager.hpp>
#include <random>

#define EM entityManager

using std::cout;

// TODO, the random generator could have float value if we want to
int generate_random_number(int start, int end) {
  // TODO see this to understand
  std::random_device rd;  // obtain a random number from hardware
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(start, end);
  return distribution(gen);
}

sf::Vector2f random_pos_in_playable_area() {
  float randPositionX = (float)generate_random_number(
      GameDatas::playableAreaX[0], GameDatas::playableAreaX[1]);
  float randPositionY = (float)generate_random_number(
      GameDatas::playableAreaY[0], GameDatas::playableAreaY[1]);
  return sf::Vector2f{randPositionX, randPositionY};
}

void EM::generateHuman(ressourceManager &res) {
  std::unique_ptr<Human> ptrHuman =
      std::make_unique<Human>(idNextEntity, random_pos_in_playable_area(), res);
  cout << "spawned pnj : " << ptrHuman->to_string() << "\n";

  ++idNextEntity;
  spawned_entities.push_back(std::move(ptrHuman));
}

void EM::generateHumans(int count, ressourceManager &res) {
  for (int i = 0; i < count; i++) {
    generateHuman(res);
  }
}

void EM::addEntity(Entity *entity) { cout << "remove this"; }

bool EM::compZOrderEntity(std::unique_ptr<Entity> &a,
                          std::unique_ptr<Entity> &b) {
  return a->getPosition().y < b->getPosition().y;
}

void EM::sortEntityByZOrder(
    std::vector<std::unique_ptr<Entity>> &list_entities) {
  sort(list_entities.begin(), list_entities.end(), compZOrderEntity);
}

void EM::renderEntities(sf::RenderWindow &window) {
  sortEntityByZOrder(spawned_entities);
  for (const auto &entity : spawned_entities) {
    entity->render(window);
  }
}

void EM::swapStateToMoveEntities(float ratioToMove) {
  // TODO add the same for Idle
  for (auto &e : spawned_entities) {
    double a = (double)rand() / RAND_MAX;
    if (a < ratioToMove && e->canHaveNewDestination()) {
      sf::Vector2f vec = random_pos_in_playable_area();
      cout << "New destination" << vec.x << "/" << vec.y << "\n";
      e->setDestination(vec);
    }
  }
}

void EM::swapStateToIdleEntities(float ratioToIdle) {
  // TODO add the same for Idle
  for (auto &e : spawned_entities) {
    double a = (double)rand() / RAND_MAX;
    if (a < ratioToIdle) {
      e->toIdle();
    }
  }
}

void EM::moveEntities() {
  for (auto &e : spawned_entities) {
    e->moveToDestination();
  }
}