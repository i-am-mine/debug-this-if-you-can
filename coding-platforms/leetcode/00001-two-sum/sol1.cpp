#include "../header/solution_interface.h"
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    for (int i = 0; i < nums.size()-1; i++){
        for (int j = i+1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target)
                return {i,j};
        }
    }

    return {-1, -1}; // Indicates no valid pair found
}
