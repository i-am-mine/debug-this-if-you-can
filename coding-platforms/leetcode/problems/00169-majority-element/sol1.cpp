#include "../header/solution_interface.h"
using namespace std;

int majorityElement(vector<int>& nums) {

    int mTimes = nums.size()/2;
    unordered_map<int, int> maj;

    for (int num: nums){
        maj[num]++;
        if (maj[num] > mTimes) return num;
    }

    return 0;

}
