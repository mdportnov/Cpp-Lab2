#include "gtest/gtest.h"
//#include "../src/lab2.20.h"
#include "../src/lab2.20.cpp"

TEST(DeltoidConstructor, DefaultConstructor){
    lab1_2::Deltoid a1;
    ASSERT_EQ(0, a1.getR());
    ASSERT_EQ(0, a1.getT());
}

TEST(DelDeltoidConstructor, InitConstructor){
    lab1_2::Deltoid a2(3);
    ASSERT_EQ(3, a2.getR());
}

TEST(DelDeltoidConstructor, TestException) {
    ASSERT_ANY_THROW(lab1_2::Deltoid a3(-3));
}

TEST(DeltoidMethods, Setters){
    lab1_2::Deltoid a(3);
    a.setR(3);
    ASSERT_EQ(3, a.getR());
    ASSERT_ANY_THROW(a.setR(-1));
}

TEST(DeltoidMethods, Parameters){
    lab1_2::Deltoid a(3);
    lab1_2::Deltoid a1;

    ASSERT_EQ(0, a1.getR());

    a.setT(2);
    ASSERT_EQ(2, a.getT());

    const double PI=3.14159, err=0.0001;
    ASSERT_STREQ("\nX=2*r*cos(t)+r*cos(2t)\nY=2*r*sin(t)-r*sin(t)\n\n", a.getEquationString());

    ASSERT_EQ(12, a.getIntersectionLength());
    ASSERT_EQ(48, a.getLength());
    ASSERT_NEAR(56.5487, a.getArea(), err);
    ASSERT_NEAR(-4.45781188187, a.getX(2), err);
    ASSERT_NEAR(7.7261920468778, a.getY(2), err);

    lab1_2::Point p{-4.45781188187369, 7.7261920468778742};
    ASSERT_NEAR(p.x, a.getXY().x, err);
    ASSERT_NEAR(p.y, a.getXY().y, err);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}