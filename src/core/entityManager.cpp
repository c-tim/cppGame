#include <Human.hpp>
#include <crops.hpp>
#include <entityManager.hpp>
#include <inputManager.hpp>
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

void EM::generatePlayer(ressourceManager &res) {
  std::unique_ptr<player>  p = std::make_unique<player>(idNextEntity, random_pos_in_playable_area(), res);
  ++idNextEntity;
    cout << "spawned human : " << p->to_string() << "\n";
  player *p_ptr = p.get();

  spawned_entities.push_back(std::move(p));
  players.push_back(p_ptr);
}


void EM::generateHumans(int count, ressourceManager &res) {
  for (int i = 0; i < count; i++) {
    generateHuman(res);
  }
}


void EM::generateCrop(ressourceManager &res, sf::Vector2f pos){
  std::unique_ptr<crop>  p = std::make_unique<crop>(idNextEntity, pos, res);
  ++idNextEntity;
    cout << "spawned crop : " << p->to_string() << "\n";

  spawned_entities.push_back(std::move(p));
}
void EM::addEntity(Entity *entity) { cout << "remove this"; }

bool EM::compZOrderEntity(std::unique_ptr<Entity> &a,
                          std::unique_ptr<Entity> &b) {
  return a->getPosition().y < b->getPosition().y;
}

void EM::sortEntityByZOrder(
    // TODO adjust zorder with player
    std::vector<std::unique_ptr<Entity>> &list_entities) {
  sort(list_entities.begin(), list_entities.end(), compZOrderEntity);
}

void EM::renderEntities(sf::RenderWindow &window) {
  sortEntityByZOrder(spawned_entities);
  for (const auto &entity : spawned_entities) {
    entity->render(window);
  }

 /*for (auto &e : players) {
    e.render(window);
  }*/
}

void EM::swapStateToMovePNJEntities(float ratioToMove) {
  // TODO add the same for Idle
  for (auto &e : spawned_entities) {
    double a = (double)rand() / RAND_MAX;
    if (a < ratioToMove && !e->playable && e->canHaveNewDestination()) {
      sf::Vector2f vec = random_pos_in_playable_area();
      cout << "New destination" << vec.x << "/" << vec.y << "\n";
      e->setDestination(vec);
    }
  }
}

void EM::swapStateToIdlePNJEntities(float ratioToIdle) {
  // TODO add the same for Idle
  for (auto &e : spawned_entities) {
    double a = (double)rand() / RAND_MAX;
    if (a < ratioToIdle && !e->playable) {
      e->toIdle();
    }
  }
}

void EM::moveEntities() {
  //TODO remove i (used for debuuger)
  int i=0;
  for (auto &e : spawned_entities) {
    e->move();
    i++;
  }
}

void EM::checkInputOtherActionsPlayers(ressourceManager &res) {
    crop_to_plant_queue.clear();

//cout<<" qedd "<< players.size()<<"\n";
    for (auto &e : players) {
      player p = *e;
    getInputCrop(p);
  }

  for(auto &pos : crop_to_plant_queue){
    generateCrop(res, pos);
  }

}

  void EM::addCropPoseToQueue(sf::Vector2f pos){
    crop_to_plant_queue.push_back(pos);
  }











