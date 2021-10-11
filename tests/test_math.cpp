#include <iostream>
#include "gtest/gtest.h"
#include "../src/myMath/vec2.hpp"
#include "../src/myMath/utils.hpp"
#include <vector>

// blank namespace to avoid implementation collision
namespace {

	/*TEST(Vec2, Init) {
		ASSERT_EQ(vec2(), vec2(0., 0.)) << "Initialization without arguments";
		vec2 a = vec2(2.5, 5.5);
		ASSERT_EQ(a, vec2(2.5, 5.5)) << "Initialization with arguments";
	}*/

	TEST(Vec2, Methods) {
		Vec2 a = Vec2(4., 3.);
		Vec2 b = Vec2(0., 1.);
		ASSERT_NEAR(a.norm(), 5., 1e-3) << "Norm";
		// ASSERT_EQ(a.normalize(), Vec2(0.8, 0.6)) << "Normalized vector";
		ASSERT_NEAR(a.angle(), 0.644, 1e-3) << "angle";
		ASSERT_NEAR(a.anglebt(b), 0.927, 1e-3) << "anglebt";
		ASSERT_NEAR(a.dot(b), 3., 1e-3) << "dot";
		ASSERT_NEAR(a.x(), 4., 1e-3) << "get x";
		ASSERT_NEAR(a.y(), 3., 1e-3) << "get y";
	}

	TEST(Functions, All) {
		Vec2 a = Vec2(4., 3.);
		Vec2 b = Vec2(0., 1.);
		ASSERT_NEAR(distance(a, b), 4.472, 1e-3) << "Distance";
		/*std::vector<Vec2> vecs;
		vecs.push_back(a);
		vecs.push_back(b);
		ASSERT_EQ(barycenter(vecs), Vec2(2., 2.)) << "Barycenter";*/
	}
}
