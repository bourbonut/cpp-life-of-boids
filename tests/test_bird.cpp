#include <iostream>
#include "gtest/gtest.h"
#include "../src/Bird.hpp"
#include "../src/Flock.hpp"
#include <vector>

namespace {


	TEST(TestBird, Instanciation) {
		Vec2 v = Vec2(3.0f, 3.0f);
		Bird b = Bird(v, v);

		ASSERT_EQ(b.getPosition().x, b.getVelocity().x) << "Basic instanciation with one vector and test equality of x";
		ASSERT_EQ(b.getPosition().y, b.getVelocity().y) << "Basic instanciation with one vector and test equality of y";
	}


	TEST(TestFlock, InstanciationAndAddingAgents) {
		Flock flock(300);
		//Initializing a flock with pop size 300 and checking size of vector population
		ASSERT_EQ(flock.getPopSize(), 300) << "Population size should be 300";

		//Adding one agent and checking size
		flock.addAgent();
		ASSERT_EQ(flock.getPopSize(), 301) << "Added an agent with addAgent(), now popSize should be 301";
	
		//Adding 1000 agents
		for (int i = 0; i < 1000; ++i) {
			flock.addAgent();
		}
		ASSERT_EQ(flock.getPopSize(), 1301) << "Added 100 agents, now popSize should be 1301";

	}
	/*TEST(Functions, All) {

	}*/
}