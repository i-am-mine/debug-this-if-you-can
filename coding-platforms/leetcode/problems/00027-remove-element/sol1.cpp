#include "../header/solution_interface.h"
using namespace std;

int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) return 0;

    int right = nums.size()-1;
    int i {0};

    while(i < right) {
        if (nums[i] == val) {
            nums[i] = nums[right];
            right--;
        }
        else
            i++;
    }

    if (nums[i] == val) i--;

    return i+1;
}
