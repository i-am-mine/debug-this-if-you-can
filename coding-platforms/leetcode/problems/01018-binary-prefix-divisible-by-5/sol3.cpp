#include "../header/solution_interface.h"
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res;
    res.reserve(nums.size());

    int r = 0;
    for(auto &bit: nums){
        r = ((r << 1) | bit) % 5;
        res.push_back(r == 0);
    }

    return res;
}
