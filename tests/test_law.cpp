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
        int size = 2;
        Flock* flockPtr = nullptr;
        std::vector<Agent*> mainFlock;

        mainFlock.reserve(size);
        mainFlock.push_back(new Bird{ Vec2(0.f, 0.f), Vec2(0.f, 1.f) });
        mainFlock.push_back(new Bird{ Vec2(0.5f, 0.5f), Vec2(1.f, -1.f) });
        mainFlock.push_back(new Bird{ Vec2(-0.5f, 0.5f), Vec2(0.f, -1.f) });


        Flock flock{ mainFlock };
        flockPtr = &flock;

        std::vector<Vec2> alignments;

        for (auto& bird : *flockPtr) {

            std::tuple<std::vector<Agent*>, std::vector<Agent*>> allNeighbors = (*flockPtr).computeNeighbors(*bird);
            std::vector<Agent*> bVec = std::get<0>(allNeighbors);
            std::vector<Agent*> eVec = std::get<1>(allNeighbors);
            AlignmentLaw law;
            Vec2 vecAlignment = law.compute(*bird, bVec);
            alignments.push_back(vecAlignment);
            //std::cout << "Bird " << (*bird)._id << " | Alignment Law : " << vecAlignment << '\n';
        }

        EXPECT_EQ(alignments[0].x, 0.5f);
        EXPECT_EQ(alignments[0].y, -1.f);
        EXPECT_EQ(alignments[1].x, 0.f);
        EXPECT_EQ(alignments[1].y, 0.f);
        EXPECT_EQ(alignments[2].x, 1.f);
        EXPECT_EQ(alignments[2].y, -1.f);
	}

    TEST(CohesionLaw, BasicTests) {

    }

    TEST(SeparationLaw, BasicTests) {

    }
}