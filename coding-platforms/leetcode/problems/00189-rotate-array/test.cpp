#include "../header/solution_interface.h"
#include <gtest/gtest.h>

using namespace std;

struct RotateArrayTestCase {
    vector<int> nums;
    int k;
    vector<int> expected;
};

class RotateArrayTests : public ::testing::TestWithParam<RotateArrayTestCase> {};

// Helper function to read array from file
vector<int> readArrayFromFile(const string& file_path, const string& prefix) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cout << "Error: Could not open file: " << file_path << endl;
        return {}; // return empty vector
    }

    string line;
    vector<int> result;

    while (getline(file, line)) {
        if (line.rfind(prefix, 0) == 0) { // found the prefix
            if (!getline(file, line)) {   // read the next line containing the numbers
                cerr << "Error: No line after prefix " << prefix << endl;
                return {};
            }

            stringstream ss(line);
            string num;
            vector<int> result;
            while (getline(ss, num, ',')) {
                if (!num.empty())
                    result.push_back(stoi(num));
            }
            return result; // successfully read
        }
    }

    return result;
}

TEST_P(RotateArrayTests, Examples) {
    auto param = GetParam();
    auto nums_copy = param.nums;  // named vector for binding
    rotate(nums_copy, param.k);   // modifies nums_copy in-place
    EXPECT_EQ(nums_copy, param.expected);  // compare after rotation
}

INSTANTIATE_TEST_SUITE_P(
    AllCases, RotateArrayTests,
    ::testing::Values(
        RotateArrayTestCase{{1,2,3,4,5,6,7}, 3, {5,6,7,1,2,3,4}},
        RotateArrayTestCase{{-1,-100,3,99}, 2, {3,99,-1,-100}},
        RotateArrayTestCase{{1,2,3}, 0, {1,2,3}},          // k = 0
        RotateArrayTestCase{{1,2,3}, 3, {1,2,3}},          // k = nums.size()
        RotateArrayTestCase{
            readArrayFromFile("./arrays_100k.txt", "Original array"),  // 10^5 elements
            1000,
            readArrayFromFile("./arrays_100k.txt", "Rotated array")
        },
        RotateArrayTestCase{
            readArrayFromFile("./arrays_1M.txt", "Original array"),  // 10^6 elements
            50000,
            readArrayFromFile("./arrays_1M.txt", "Rotated array")
        },
        RotateArrayTestCase{
            readArrayFromFile("./arrays_10M.txt", "Original array"),  // 10^7 elements
            300000,
            readArrayFromFile("./arrays_10M.txt", "Rotated array")
        },
        RotateArrayTestCase{
            readArrayFromFile("./arrays_100M.txt", "Original array"),  // 10^8 elements
            6000000,
            readArrayFromFile("./arrays_100M.txt", "Rotated array")
        }
    )
);


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




// #include "../header/solution_interface.h"
// #include <gtest/gtest.h>

// using namespace std;

// // Helper to read array from file
// vector<int> readArrayFromFile(const string& file_path, const string& prefix) {
//     ifstream file(file_path);
//     if (!file.is_open()) {
//         cout << "Error: Could not open file: " << file_path << endl;
//         return {}; // return empty vector
//     }

//     string line;
//     vector<int> result;

//     while (getline(file, line)) {
//         if (line.rfind(prefix, 0) == 0) { // found the prefix
//             if (!getline(file, line)) {   // read the next line containing the numbers
//                 cerr << "Error: No line after prefix " << prefix << endl;
//                 return {};
//             }

//             stringstream ss(line);
//             string num;
//             vector<int> result;
//             while (getline(ss, num, ',')) {
//                 if (!num.empty())
//                     result.push_back(stoi(num));
//             }
//             return result; // successfully read
//         }
//     }

//     return result;
// }

// TEST(RotateArrayLarge, FileTest) {
//     string file_path = "./arrays_100M.txt";  // adjust path if needed

//     auto original = readArrayFromFile(file_path, "Original array");
//     auto expected = readArrayFromFile(file_path, "Rotated array");

//     auto nums_copy = original;
//     int k = 1000;

//     rotate(nums_copy, k);  // rotates in-place

//     EXPECT_EQ(nums_copy, expected);
// }

// int main(int argc, char** argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
