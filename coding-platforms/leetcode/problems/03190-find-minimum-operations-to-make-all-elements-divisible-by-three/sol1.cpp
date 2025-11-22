#include "../header/solution_interface.h"
using namespace std;

int minimumOperations(vector<int>& nums) {
    int count = 0;

    for(auto &i: nums){
        if (i % 3 != 0) count++;
    }

    return count;
}
