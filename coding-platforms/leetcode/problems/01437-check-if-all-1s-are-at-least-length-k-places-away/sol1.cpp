#include "../header/solution_interface.h"
using namespace std;

bool kLengthApart(vector<int>& nums, int k) {
    if (k == 0 || nums.size() == 1) return true;

    int countDistance = k;

    for (int i: nums){
        if (i == 0) {
            countDistance++;
        }
        else {
            if (countDistance < k) return false;
            countDistance = 0;
        }
    }

    return true;
}
