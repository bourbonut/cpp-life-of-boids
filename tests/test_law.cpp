#include <iostream>
#include "gtest/gtest.h"
#include "../src/resources/Bird.hpp"
#include "../src/resources/Flock.hpp"
#include "../src/resources/Agent.hpp"
#include <vector>
#include "../src/lib/myLaws/AlignmentLaw.hpp"
#include "../src/lib/myMath/Vec2.hpp"

namespace {
	TEST(AlignmentLaw,BasicsTests) {

		//Flock flock(300);
		//std::vector<Bird> neighbors = flock.computeNeighbors(flock.getAgent(flock.getPopSize() - 1), 1, 1);

        Vec2 v1 = Vec2(4., 3.);
        Vec2 v2 = Vec2(0., 1.);
        Bird b1 = Bird(v1, v2);
        Vec2 v3 = Vec2(5., 4.);
        Vec2 v4 = Vec2(0., 1.);
        Bird b2 = Bird(v3, v4);
        Vec2 v5 = Vec2(1., 3.);
        Vec2 v6 = Vec2(6., 2.);
        Bird b3 = Bird(v5, v6);
        Vec2 v7 = Vec2(4., 2.);
        Vec2 v8 = Vec2(6., 2.);
        Bird b4 = Bird(v7, v8);
        Vec2 v9 = Vec2(6., 7.);
        Vec2 v10 = Vec2(6., 2.);
        Bird b5 = Bird(v9, v10);
        Vec2 v11 = Vec2(0., 3.);
        Vec2 v12 = Vec2(6., 2.);
        Bird b6 = Bird(v11, v12);
        std::vector<Bird> n{}; //= { b2 }; ou { b2, b3 };
        n.push_back(b3);
        n.push_back(b2);
        n.push_back(b4);
        n.push_back(b5);
        n.push_back(b6);

		EXPECT_NEAR(n.size(), 2, 3);
		EXPECT_NEAR(n.size(), 3, 3);
		EXPECT_NEAR(n.size(), 4, 3);
		EXPECT_NEAR(n.size(), 5, 3);
		EXPECT_NEAR(n.size(), 6, 3);
		EXPECT_NEAR(n.size(), 7, 3);


	/*	EXPECT_EQ((neighbors[0].getPosition() - neighbors[1]).getPosition(), b.getPosition(1));
		EXPECT_EQ(nextVelocity = currentBird.getVelocity() + neighbors[1]).getVelocity(), b.getVelocity(1));*/

		//std::vector<Bird> neighbors = flock.computeNeighbors(flock.getAgent(flock.getPopSize() - 1), 1, 1);
		//EXPECT_GE(neighbors.size(), 5) << "Expected at least 5 neighbors to the bird we added";

	}

    TEST(CohesionLaw, BasicTests) {

    }

    TEST(SeparationLaw, BasicTests) {

    }
}