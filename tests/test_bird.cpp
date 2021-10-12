#include <iostream>
#include "gtest/gtest.h"
#include "../src/Bird.hpp"
#include <vector>

namespace {


	TEST(TestBird, Instanciation) {
		Vec2 v = Vec2(3.0f, 3.0f);
		Bird b = Bird(v, v);

		ASSERT_EQ(b.getPosition().x, b.getVelocity().x) << "Basic instanciation with one vector and test equality of x";
		ASSERT_EQ(b.getPosition().y, b.getVelocity().y) << "Basic instanciation with one vector and test equality of y";


	}

	/*TEST(Functions, All) {

	}*/
}