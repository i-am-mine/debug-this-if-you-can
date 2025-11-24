#include "../header/solution_interface.h"
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res(nums.size(), false);

    int r = 0;
    for(int i = 0; i < nums.size(); ++i){
        r = (r * 2 + nums[i]) % 5;
        if (r == 0) res[i] = true;
    }

    return res;
}
