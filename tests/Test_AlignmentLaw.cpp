#include <iostream>
#include "gtest/gtest.h"
#include "../src/resources/Bird.hpp"
#include "../src/resources/Flock.hpp"
#include <vector>

namespace {
	TEST(neighbor) {
		Vec2 pos = Vec2(1, 1);
		Vec2 vel = Vec2(0, 1);
		Bird b = Bird(pos, vel);

		ASSERT_EQ(b.getPosition().x, 1);
		ASSERT_EQ(b.getPosition().y, 1);
		ASSERT_EQ(b.getVelocity().x, 0);
		ASSERT_EQ(b.getVelocity().y, 1);
		ASSERT_EQ(b.getNextVelocity().x, 0);
		ASSERT_EQ(b.getNextVelocity().y, 1);

		b.computePosition();
		ASSERT_EQ(b.getNextPosition().x, 1);
		ASSERT_EQ(b.getNextPosition().y, 2);

		b.updatePosition();
		ASSERT_EQ(b.getPosition().x, 1);
		ASSERT_EQ(b.getPosition().y, 2);
	}

		//balayage 100000 agents
		for (int i = 0; i < neighbors.size(); ++i) {
		
		}
		ASSERT_EQ(neighbors.size(), loopSizee + 100001);


		EXPECT_EQ((currentBird.getPosition() - neighbors[1]).getPosition(), b.getPosition(1));
		EXPECT_EQ(nextVelocity = currentBird.getVelocity() + neighbors[1]).getVelocity(), b.getVelocity(1)) ;

		std::vector<Bird> neighbors = flock.computeNeighbors(flock.getAgent(flock.getPopSize() - 1), 1, 1);
		EXPECT_GE(neighbors.size(), 5) << "Expected at least 5 neighbors to the bird we added";

	}

}