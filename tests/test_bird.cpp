#include <iostream>
#include "gtest/gtest.h"
#include "../src/Bird.hpp"
#include "../src/Flock.hpp"
#include <vector>

<<<<<<< HEAD
namespace {


	TEST(TestBird, Instanciation) {
		Vec2 v = Vec2(3.0f, 3.0f);
		Bird b = Bird(v, v);

		ASSERT_EQ(b.getPosition().x, b.getVelocity().x) << "Basic instanciation with one vector and test equality of x";
		ASSERT_EQ(b.getPosition().y, b.getVelocity().y) << "Basic instanciation with one vector and test equality of y";
	}


	TEST(TestFlock, InstanciationAndAddingAgents) {
		int testSize = 300;
		int loopSize = 1000;

		Flock flock(testSize);
		//Initializing a flock with pop size 300 and checking size of vector population
		ASSERT_EQ(flock.getPopSize(), testSize) << "Population size should be " << testSize;

		//Adding one agent and checking size
		flock.addAgent();
		ASSERT_EQ(flock.getPopSize(), testSize + 1) << "Added an agent with addAgent(), now popSize should be " << testSize << " +1";
	
		//Adding 1000 agents
		for (int i = 0; i < loopSize; ++i) {
			flock.addAgent();
		}
		ASSERT_EQ(flock.getPopSize(), testSize + 1001) << "Added " << loopSize << " agents, now popSize should be " << testSize << " + " << loopSize << "+ 1";


		//Adding a specific agent with specific values
		Bird b = Bird(Vec2(0, 0), Vec2(0, 0));
		flock.addAgent(b);

		ASSERT_EQ(flock.getPopSize(), testSize + loopSize + 2) << "Added one more agents, should be " << testSize << " + " << loopSize << "+ 2";
		flock.print();

		EXPECT_EQ(flock.getAgent(testSize + loopSize + 1).getPosition(), b.getPosition()) << "Last agent's position should be 0,0";
		EXPECT_EQ(flock.getAgent(testSize + loopSize + 1).getVelocity(), b.getVelocity()) << "Last agent's velocity should be 0,0";

		flock.addAgent(b);
		flock.addAgent(b);
		flock.addAgent(b);
		flock.addAgent(b);
		flock.addAgent(b);

		std::vector<Bird> neighbors = flock.computeNeighbors(flock.getAgent(flock.getPopSize() - 1), 1, 1);
		EXPECT_GE(neighbors.size(), 5) << "Expected at least 5 neighbors to the bird we added";

		for (Bird b : neighbors) {
			std::cout << " : Pos(" << b.getPosition().x << ", " << b.getPosition().y << ")  //  Vel(" << b.getVelocity().x << ", " << b.getVelocity().y << ")" << std::endl;
		}
		//std::vector<Bird> neighbors = flock.computeNeighbors(flock.getAgent(1000)
	}


<<<<<<< HEAD
	TEST(TestFlock, NeighborhoodComputing) {

	}
=======
	}*/
=======
TEST(Bird, Methods) {
	Vec2 position = Vec2(1., 1.);
	Vec2 velocity = Vec2(0., 1.);
	Bird bird = Bird(position, velocity);
	std::cout << "Position X: " << bird.getPosition().x() << std::endl;
	ASSERT_NEAR(bird.getPosition().x(), 1, 1e-6);
	ASSERT_NEAR(bird.getPosition().y(), 1, 1e-6);
	ASSERT_NEAR(bird.getNextPosition().x(), 1, 1e-6);
	ASSERT_NEAR(bird.getNextPosition().y(), 1, 1e-6);
	ASSERT_NEAR(bird.getVelocity().x(), 0, 1e-6);
	ASSERT_NEAR(bird.getVelocity().y(), 1, 1e-6);
	ASSERT_NEAR(bird.getNextVelocity().x(), 0, 1e-6);
	ASSERT_NEAR(bird.getNextVelocity().y(), 1, 1e-6);

	bird.computePosition();
	ASSERT_NEAR(bird.getNextPosition().x(), 1, 1e-6);
	ASSERT_NEAR(bird.getNextPosition().y(), 2, 1e-6);

	bird.updatePosition();
	ASSERT_NEAR(bird.getPosition().x(), 1, 1e-6);
	ASSERT_NEAR(bird.getPosition().y(), 2, 1e-6);
	ASSERT_NEAR(bird.getVelocity().x(), 0, 1e-6);
	ASSERT_NEAR(bird.getVelocity().y(), 1, 1e-6);
	//ASSERT_NEAR(a.norm(), 5., 1e-3) << "Norm";
>>>>>>> Enriches the tests
>>>>>>> Enriches the tests
}