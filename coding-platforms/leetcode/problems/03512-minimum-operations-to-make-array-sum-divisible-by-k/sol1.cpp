#include "../header/solution_interface.h"
using namespace std;

int minOperations(vector<int>& nums, int k) {
    return accumulate(nums.begin(), nums.end(), 0) % k;
}
