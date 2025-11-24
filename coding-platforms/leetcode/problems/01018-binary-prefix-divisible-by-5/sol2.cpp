#include "../header/solution_interface.h"
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res;

    int r = 0;
    for(auto &num: nums){
        r = (r * 2 + num) % 5;
        res.push_back(r == 0);
    }

    return res;
}
