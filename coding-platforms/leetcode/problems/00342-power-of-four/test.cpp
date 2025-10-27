#include "../header/solution_interface.h"
#include <gtest/gtest.h>

using namespace std;

TEST(PowerOfFour, Ex1) { EXPECT_EQ(isPowerOfFour(16), true); }
TEST(PowerOfFour, Ex2) { EXPECT_EQ(isPowerOfFour(5), false); }
TEST(PowerOfFour, Ex3) { EXPECT_EQ(isPowerOfFour(1), true); }
TEST(PowerOfFour, Negative) { EXPECT_EQ(isPowerOfFour(-4), false); }
TEST(PowerOfFour, Zero) { EXPECT_EQ(isPowerOfFour(0), false); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
