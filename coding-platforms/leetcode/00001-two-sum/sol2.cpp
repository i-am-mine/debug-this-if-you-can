#include "../header/solution_interface.h"
using namespace std;


vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
        if (seen.count(target - nums[i]))
            return {i, seen[target - nums[i]]};
        else
            seen[nums[i]] = i;
    }

    return {-1, -1}; // Indicates no valid pair found
}
