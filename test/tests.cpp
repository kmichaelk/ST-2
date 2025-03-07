// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"

class CircleFixture
    : public ::testing::TestWithParam<std::tuple<double, double, double>> {
};

TEST_F(CircleFixture, ThrowsIfRadiusIsNegative) {
    Circle circle(0);
    EXPECT_ANY_THROW(circle.setRadius(-1));
}
TEST_F(CircleFixture, ThrowsIfRadiusIsNegative_ViaCtor) {
    EXPECT_ANY_THROW(Circle circle(-1));
}
TEST_F(CircleFixture, ThrowsIfFerenceIsNegative) {
    Circle circle(0);
    EXPECT_ANY_THROW(circle.setFerence(-1));
}
TEST_F(CircleFixture, ThrowsIfAreaIsNegative) {
    Circle circle(0);
    EXPECT_ANY_THROW(circle.setArea(-1));
}

TEST_P(CircleFixture, SetRadius) {
    const auto &[radius, ference, area] = GetParam();

    Circle circle(0);
    circle.setRadius(radius);
    ASSERT_DOUBLE_EQ(circle.getRadius(), radius);

    EXPECT_DOUBLE_EQ(circle.getFerence(), ference);
    EXPECT_DOUBLE_EQ(circle.getArea(), area);
}
TEST_P(CircleFixture, SetFerence) {
    const auto &[radius, ference, area] = GetParam();

    Circle circle(0);
    circle.setFerence(ference);
    ASSERT_DOUBLE_EQ(circle.getFerence(), ference);

    EXPECT_DOUBLE_EQ(circle.getRadius(), radius);
    EXPECT_DOUBLE_EQ(circle.getArea(), area);
}
TEST_P(CircleFixture, SetArea) {
    const auto &[radius, ference, area] = GetParam();

    Circle circle(0);
    circle.setArea(area);
    ASSERT_DOUBLE_EQ(circle.getArea(), area);

    EXPECT_DOUBLE_EQ(circle.getRadius(), radius);
    EXPECT_DOUBLE_EQ(circle.getFerence(), ference);
}
INSTANTIATE_TEST_SUITE_P(
    Circle,
    CircleFixture,
    ::testing::Values(
        std::make_tuple(0, 0.0, 0.0),
        std::make_tuple(1, 6.283185307179586, 3.141592653589793),
        std::make_tuple(2, 12.566370614359172, 12.566370614359172),
        std::make_tuple(3, 18.84955592153876, 28.274333882308138),
        std::make_tuple(4, 25.132741228718345, 50.26548245743669),
        std::make_tuple(5, 31.41592653589793, 78.53981633974483),
        std::make_tuple(6, 37.69911184307752, 113.09733552923255),
        std::make_tuple(7, 43.982297150257104, 153.93804002589985),
        std::make_tuple(8, 50.26548245743669, 201.06192982974676),
        std::make_tuple(9, 56.548667764616276, 254.46900494077323),
        std::make_tuple(10, 62.83185307179586, 314.1592653589793)));

TEST(task1, YieldsCorrectAnswer) {
    EXPECT_FLOAT_EQ(task1(6378100), 0.15915494);
}
TEST(task2, YieldsCorrectAnswer) {
    EXPECT_FLOAT_EQ(task2(3, 1000, 2000, 1), 72256.633);
}
