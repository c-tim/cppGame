#include <gtest/gtest.h>

#include <string>

#include "Player.hpp"
#include "Human.hpp"
#include "entityState.hpp"

#include "ressourcesLoader.hpp"

// trivial test to verify unit test implementation
TEST(TestGame, alwaysValid) {
  EXPECT_EQ(1, 1);
}


TEST(TestGame, correctDirectionTrivialRight) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
   // h.state.setCurrentDirection(entityState::UP);

  h.setDestination(sf::Vector2f{18,15});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::RIGHT);

}

TEST(TestGame, correctDirectionTrivialLeft) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
   //   h.state.setCurrentDirection(entityState::UP);

  h.setDestination(sf::Vector2f{-40,15});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::LEFT);

}

TEST(TestGame, correctDirectionTrivialUp) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
  h.setDestination(sf::Vector2f{4,-100});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::UP);

}

TEST(TestGame, correctDirectionTrivialDown) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
  h.setDestination(sf::Vector2f{-4,100});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::DOWN);

}


TEST(TestGame, correctDirectionLeftWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
 // h.state.setCurrentDirection(entityState::LEFT);
  //both coords are different, the one that must be chosen is the one already taken
  h.setDestination(sf::Vector2f{-10,40});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::LEFT);

}

TEST(TestGame, correctDirectionRightWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
 // h.state.setCurrentDirection(entityState::RIGHT);
  h.setDestination(sf::Vector2f{5,40});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::RIGHT);

}

TEST(TestGame, correctDirectionUpWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
  //h.state.setCurrentDirection(entityState::)
  h.setDestination(sf::Vector2f{4,-100});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::UP);

}

TEST(TestGame, correctDirectionDownWithAlreadyDefinedDirection) {
  ressourceManager res;
  Human h{0, sf::Vector2f{4,15}, res};
  //h.state.setCurrentDirection(entityState::)
  h.setDestination(sf::Vector2f{-4,100});
    EXPECT_EQ( h.state.getAxisMoving(h.getDirectionFromDestination()), entityState::DOWN);

}

