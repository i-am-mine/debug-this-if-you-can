#include "../header/solution_interface.h"
#include <gtest/gtest.h>

using namespace std;

TEST(PowerOfTwo, Ex1) { EXPECT_EQ(isPowerOfTwo(1), true); }
TEST(PowerOfTwo, Ex2) { EXPECT_EQ(isPowerOfTwo(16), true); }
TEST(PowerOfTwo, Ex3) { EXPECT_EQ(isPowerOfTwo(3), false); }
TEST(PowerOfTwo, Negative) { EXPECT_EQ(isPowerOfTwo(-4), false); }
TEST(PowerOfTwo, Zero) { EXPECT_EQ(isPowerOfTwo(0), false); }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
