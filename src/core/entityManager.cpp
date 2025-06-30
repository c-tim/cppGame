#include <Human.hpp>
#include <coucouVisitor.hpp>
#include <crops.hpp>
#include <entityManager.hpp>
#include <inputManager.hpp>
#include <random>

#define EM entityManager
#define key sf::Keyboard::Key

using std::cout;

// TODO, the random generator could have float value if we want to
int generate_random_number(int start, int end) {
  // TODO see this to understand (I dont understand this, it came from other
  // code)
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
  ++idNextEntity;
  spawned_entities.push_back(std::move(ptrHuman));
}

void EM::generatePlayer(ressourceManager &res, int index_Player) {
  std::unique_ptr<player> p = std::make_unique<player>(
      idNextEntity, random_pos_in_playable_area(), res);
  ++idNextEntity;
  setPlayerInfo(index_Player, p->keyPlayer);
  player *p_ptr = p.get();

  spawned_entities.push_back(std::move(p));
  players.push_back(p_ptr);
}

void EM::generateHumans(int count, ressourceManager &res) {
  for (int i = 0; i < count; i++) {
    generateHuman(res);
  }
}

void EM::generateCrop(ressourceManager &res, sf::Vector2f pos) {
  std::unique_ptr<crop> p = std::make_unique<crop>(idNextEntity, pos, res);
  ++idNextEntity;

  spawned_entities.push_back(std::move(p));
}
void EM::addEntity(Entity *entity) { cout << "remove this"; }

void EM::destroyEntity(Entity *entity_to_destroy) {
 // std::unique_ptr<Entity> e = std::find(spawned_entities.begin(), spawned_entities.end(), &entity_to_destroy);
 auto e = std::find_if(std::begin(spawned_entities), 
                        std::end(spawned_entities), 
                        [entity_to_destroy](auto &element) { return element.get() == entity_to_destroy;});   
  if(e!=spawned_entities.end()){
  spawned_entities.erase(e);

  }

}

// choose the Zorder and then the y position to select the priority to render
bool EM::compZOrderEntity(std::unique_ptr<Entity> &a,
                          std::unique_ptr<Entity> &b) {
  if (a->zOrder != b->zOrder) {
    return a->zOrder > b->zOrder;
  }
  return a->getPosition().y < b->getPosition().y;
}

void EM::sortEntityByZOrder(
    // DONE adjust zorder with player
    std::vector<std::unique_ptr<Entity>> &list_entities) {
  sort(list_entities.begin(), list_entities.end(), compZOrderEntity);
}

/*Call render for each entity*/
void EM::renderEntities(sf::RenderWindow &window) {
  sortEntityByZOrder(spawned_entities);
  for (const auto &entity : spawned_entities) {
    entity->render(window);
  }
}

/* For each entity, if random test past (ratioToMove), set a destination to
 * humans*/
void EM::swapStateToMovePNJEntities(float ratioToMove) {
  // DONE add the same for Idle
  for (auto &e : spawned_entities) {
    double a = (double)rand() / RAND_MAX;
    if (a < ratioToMove && !e->playable && e->canHaveNewDestination()) {
      sf::Vector2f vec = random_pos_in_playable_area();
      e->setDestination(vec);
    }
  }
}

void EM::swapStateToIdlePNJEntities(float ratioToIdle) {
  for (auto &e : spawned_entities) {
    double a = (double)rand() / RAND_MAX;
    if (a < ratioToIdle && !e->playable) {
      e->toIdle();
    }
  }
}

void EM::moveEntities() {
  // TODO remove i (used for debuuger)
  int i = 0;
  for (auto &e : spawned_entities) {
    e->move();
    i++;
  }
}

/*Check if players wants to plant crop*/
void EM::checkInputOtherActionsPlayers(ressourceManager &res) {
  crop_to_plant_queue.clear();
  // First we collect the positions of all the players who want to plant crops
  for (auto &e : players) {
    player p = *e;
    if (tick_since_lastPlant_grow >= GameDatas::COOLDOWN_PLANT_TREE) {
      if (getInputCrop(p)) {
        tick_since_lastPlant_grow = 0;
      }
    }
  }

  // Then we plant them at the correct position, to prevent a modification of
  // spawned_entities during its reading
  for (auto &pos : crop_to_plant_queue) {
    generateCrop(res, pos);
  }
}

/*Used for the method above*/
void EM::addCropPoseToQueue(sf::Vector2f pos) {
  crop_to_plant_queue.push_back(pos);
}

/* Test for the pattern visitor (the pattern is not used for other purpose)*/
void EM::faitLAppel() { coucouVisitor appel{&spawned_entities}; }

void EM::moveSelectedEntityOrUnSelectIt(sf::Vector2f mousePos) {
  // Soit une entité a deja ete selectionne avant et le click la deselectionne
  if (currentEntitySelected != nullptr) {
    cout << "RELEASE SELECTED \n";
    currentEntitySelected->setPosition((sf::Vector2f)mousePos);
    currentEntitySelected->toIdle();
    currentEntitySelected->zOrder = 0;
    currentEntitySelected = nullptr;
  }
  // soit on regarde si une nouvelle entite est selectionnée
  else {
    currentEntitySelected =
        getPickableEntitySelected(&spawned_entities, mousePos);
    if (currentEntitySelected != nullptr) {
      currentEntitySelected->has_destination = false;
      currentEntitySelected->state.isFlying();
      currentEntitySelected->zOrder = -5;
      // TODO here change the animation to
      // grabbed later if time (pas implemente mais je voulais mettre une
      // animation de personnage qui agite les bras)
    }
  }
}

void EM::moveSelectedPlayerToMouse(sf::Vector2f mousePos) {
  if (currentEntitySelected != nullptr) {
    currentEntitySelected->setPosition((sf::Vector2f)mousePos);
    currentEntitySelected->has_destination = false;
  }
}

Entity *EM::getPickableEntitySelected(
    std::vector<std::unique_ptr<Entity>> *list, sf::Vector2f mousePos) {
  for (auto const &e : *list) {
    if (e->pickable && e->isSpriteInBoundOfPos(mousePos)) {
      return e.get();
    }
  }
  return nullptr;
}

Entity *EM::getEntitySelected() {
  // not optimal but works
  if (currentEntitySelected == nullptr) {
    return nullptr;
  }
  if (currentEntitySelected->pickable) {
    return (Entity *)currentEntitySelected;
  }
  return nullptr;
}

/*Conserve les touches de tout les joueurs (peut etre etendue a plusieurs
 * joueurs)*/
void setPlayerInfo(int index, struct player_info &info) {
  if (index == 0) {
    info = {key::Up, key::Left, key::Down, key::Right, key::Semicolon};
  } else if (index == 1) {
    info = {key::Z, key::Q, key::S, key::D, key::E};
  }
}
