#include "../header/solution_interface.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>        // For UnorderedElementsAre

using namespace std;
using ::testing::UnorderedElementsAreArray;

// TEST(TwoSum, Ex1) {
//     EXPECT_THAT(twoSum(vector<int>{2, 7, 11, 15}, 9), UnorderedElementsAre(0, 1));
// }
// TEST(TwoSum, Ex2) {
//     EXPECT_THAT(twoSum(vector<int>{3, 2, 4}, 6), UnorderedElementsAre(1, 2));
// }
// TEST(TwoSum, Ex3) {
//     EXPECT_THAT(twoSum(vector<int>{3, 3}, 6), UnorderedElementsAre(0, 1));
// }

struct TwoSumTestCase {
    vector<int> nums;
    int target;
    vector<int> expected;
};

class TwoSumTests : public ::testing::TestWithParam<TwoSumTestCase> {};

TEST_P(TwoSumTests, MultipleCases) {
    auto param = GetParam();
    auto nums_copy = param.nums;  // named vector for binding
    EXPECT_THAT(twoSum(nums_copy, param.target),
                UnorderedElementsAreArray(param.expected));
}

INSTANTIATE_TEST_SUITE_P(
    AllCases, TwoSumTests,
    ::testing::Values(
        TwoSumTestCase{{2,7,11,15}, 9, {0,1}},
        TwoSumTestCase{{3,2,4}, 6, {1,2}},
        TwoSumTestCase{{3,3}, 6, {0,1}}
        // add thousands more here
    )
);

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
