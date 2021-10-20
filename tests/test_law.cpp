#include <iostream>
#include "gtest/gtest.h"
#include "../src/resources/model/Bird.hpp"
#include "../src/resources/model/Flock.hpp"
#include "../src/resources/model/Agent.hpp"
#include <vector>
#include "../src/lib/myLaws/AlignmentLaw.hpp"
#include "../src/lib/myMath/Vec2.hpp"

namespace {
	TEST(AlignmentLaw,BasicsTests) {

	}

    TEST(CohesionLaw, BasicTests) {
        Flock* TEST_pFLOCK = nullptr;
        std::vector<Agent*> testFlock;

        int size = 400;

        testFlock.reserve(size);
        for (int i = 0; i < size; ++i) {
            testFlock.push_back(new Bird{});
        }
        Flock flock{ testFlock };

        TEST_pFLOCK = &flock;

        Vec2 v1 = Vec2(4., 3.);
        Vec2 v2 = Vec2(0., 1.);
        Agent& b1 = Bird(v1, v2);
        Vec2 v3 = Vec2(5., 3.);
        Vec2 v4 = Vec2(0., 1.);
        Agent& b2 = Bird(v3, v4);
        Vec2 v5 = Vec2(36., 3.);
        Vec2 v6 = Vec2(6., 2.);
        Bird b3 = Bird(v5, v6);
        std::vector<Agent*> n{};
        n.push_back(new Bird(v5, v6));
        std::cout << distance(b1.getPosition(),b3.getPosition()) << '\n';
        CohesionLaw m_cohesionLaw;
        Vec2 vecCohesion = m_cohesionLaw.compute(b1, n);
        EXPECT_NEAR(vecCohesion.x, 100, 3);
    }

    TEST(SeparationLaw, BasicTests) {
        Flock* TEST_pFLOCK = nullptr;
        std::vector<Agent*> testFlock;

        int size = 400;

        testFlock.reserve(size);
        for (int i = 0; i < size; ++i) {
            testFlock.push_back(new Bird{});
        }
        Flock flock{ testFlock };

        TEST_pFLOCK = &flock;

        Vec2 v1 = Vec2(4., 3.);
        Vec2 v2 = Vec2(0., 1.);
        Agent &b1 = Bird(v1, v2);
        Vec2 v3 = Vec2(5., 3.);
        Vec2 v4 = Vec2(0., 1.);
        Agent &b2 = Bird(v3, v4);
        //Vec2 v5 = Vec2(1., 3.);
        //Vec2 v6 = Vec2(6., 2.);
        //Bird b3 = Bird(v5, v6);
        //Vec2 v7 = Vec2(4., 2.);
        //Vec2 v8 = Vec2(6., 2.);
        //Bird b4 = Bird(v7, v8);
        //Vec2 v9 = Vec2(6., 7.);
        //Vec2 v10 = Vec2(6., 2.);
        //Agent &b5 = Bird(v9, v10);
        //Vec2 v11 = Vec2(0., 3.);
        //Vec2 v12 = Vec2(6., 2.);
        //Bird b6 = Bird(v11, v12);
        std::vector<Agent*> n{}; //= { b2 }; ou { b2, b3 };
        //n.push_back(b3);
        //n.emplace_back(b2);
        n.push_back(new Bird(v3, v4));
        SeparationLaw m_separationLaw;
        Vec2 vecSeparation = m_separationLaw.compute(b1, n);
        EXPECT_NEAR(vecSeparation.x, -1, 0.1);
        //n.push_back(b2);
        //EXPECT_NEAR(n.size(), 3, 3);
        //n.push_back(b4);
        //n.push_back(b5);
        //n.push_back(b6);
    }
}