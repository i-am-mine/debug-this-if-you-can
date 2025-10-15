#include "../header/solution_interface.h"
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 1) return 1;

    int i = 0;

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}
