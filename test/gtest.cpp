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
    a.setT(2);
    ASSERT_EQ(2, a.getT());

    const double PI=3.14159, err=0.0001;
    ASSERT_NEAR(PI, a.getArea(), err);


}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}