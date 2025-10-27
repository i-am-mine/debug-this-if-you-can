#include "../header/solution_interface.h"
#include <gtest/gtest.h>

using namespace std;

TEST(PowerOfThree, Ex1) { EXPECT_EQ(isPowerOfThree(27), true); }
TEST(PowerOfThree, Ex2) { EXPECT_EQ(isPowerOfThree(0), false); }
TEST(PowerOfThree, Ex3) { EXPECT_EQ(isPowerOfThree(-1), false); }
TEST(PowerOfThree, Power0) { EXPECT_EQ(isPowerOfThree(1), true); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
