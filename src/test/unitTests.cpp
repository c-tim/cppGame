#include <gtest/gtest.h>

#include <string>

#include "Human.hpp"
#include "Player.hpp"
#include "entityManager.hpp"
#include "entityState.hpp"
#include "ressourcesLoader.hpp"
#include "gameManager.hpp"



// trivial test to verify unit test implementation
TEST(TestGame, alwaysValid) { EXPECT_EQ(1, 1); }

TEST(TestGame, correctDirectionTrivialRight) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::DOWN);

  h.setDestination(sf::Vector2f{18, 15});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::RIGHT);
}

TEST(TestGame, correctDirectionTrivialLeft) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::UP);

  h.setDestination(sf::Vector2f{-40, 15});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::LEFT);
}

TEST(TestGame, correctDirectionTrivialUp) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::DOWN);

  h.setDestination(sf::Vector2f{4, -100});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::UP);
}

TEST(TestGame, correctDirectionTrivialDown) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::UP);

  h.setDestination(sf::Vector2f{4, 100});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::DOWN);
}

TEST(TestGame, correctDirectionLeftWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::LEFT);
  // both coords are different, the one that must be chosen is the one already
  // taken
  h.setDestination(sf::Vector2f{-10, 40});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::LEFT);
}

TEST(TestGame, correctDirectionRightWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::RIGHT);
  h.setDestination(sf::Vector2f{10, 40});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::RIGHT);
}

TEST(TestGame, correctDirectionUpWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::UP);
  h.setDestination(sf::Vector2f{4500, -100});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::UP);
}

TEST(TestGame, correctDirectionDownWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  h.state.setCurrentDirection(entityState::DOWN);
  h.setDestination(sf::Vector2f{456, 25});
  EXPECT_EQ(h.state.getAxisMoving(h.getDirectionFromDestination()),
            entityState::DOWN);
}

TEST(TestGame, dirToVecDirValidation) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};

  sf::Vector2i up{0, -1};
  sf::Vector2i down{0, 1};
  sf::Vector2i left{-1, 0};
  sf::Vector2i right{1, 0};
  EXPECT_EQ(h.state.dirToVecDir(entityState::UP), up);
  EXPECT_EQ(h.state.dirToVecDir(entityState::DOWN), down);
  EXPECT_EQ(h.state.dirToVecDir(entityState::LEFT), left);
  EXPECT_EQ(h.state.dirToVecDir(entityState::RIGHT), right);
}

TEST(TestGame, vecDirToDirValidation) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};

  EXPECT_EQ(h.state.vecDirToDir(sf::Vector2f{0, -15}), entityState::UP);
  EXPECT_EQ(h.state.vecDirToDir(sf::Vector2f{0, 47}), entityState::DOWN);
  EXPECT_EQ(h.state.vecDirToDir(sf::Vector2f{-656, 0}), entityState::LEFT);
  EXPECT_EQ(h.state.vecDirToDir(sf::Vector2f{1, 0}), entityState::RIGHT);
}

TEST(TestGame, randomPosInPlayableArea) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  for (size_t i = 0; i < 100; i++) {
    sf::Vector2f pos = random_pos_in_playable_area();
    EXPECT_TRUE(pos.x >= GameDatas::playableAreaX[0]);
    EXPECT_TRUE(pos.x <= GameDatas::playableAreaX[1]);
    EXPECT_TRUE(pos.y >= GameDatas::playableAreaY[0]);
    EXPECT_TRUE(pos.y <= GameDatas::playableAreaY[1]);
  }
}


TEST(TestGame, pnjReachDestination) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4, 15}, res};
  for (size_t i = 0; i < 2; i++) {
    sf::Vector2f pos = random_pos_in_playable_area();
    sf::Vector2f destination = random_pos_in_playable_area();
    h.setPosition(pos);
    h.setDestination(destination);
    gameManager g{};
    

    for (int i = 0; i < 50; i++) {
          g.setDeltaTime();
      h.moveToDestination();
    }

    std::cout << "[RESULT] pos : " << h.getPosition().x << "/"
              << h.getPosition().y << " , destination " << destination.x << "/"
              << destination.y << "\n";
    EXPECT_EQ(h.getPosition(), destination);
  }
}
