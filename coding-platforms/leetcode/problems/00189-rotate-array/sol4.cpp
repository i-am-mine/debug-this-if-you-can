#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1     <= nums.length <= 10^5
 * -2^31 <= nums[i]     <= 2^31-1
 * 0     <= k           <= 10^5
 */

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    if (k == 0) return;
    if (nums.size() == 1) return;

    int j = nums.size() - k;
    int i = 0, pivot = i;

    while(j < nums.size()){
        swap(nums[i],nums[j]);

        // update pivot
        if (i == pivot) pivot = j;

        i++;
        j++;
    }

    j = pivot;
    if (j == i) return;

    while(i < nums.size()-1){

        if (j == nums.size()) j = pivot;
        if (j == i) return;

        swap(nums[i],nums[j]);

        // update pivot
        if (i == pivot) pivot = j;

        i++;
        j++;
    }
}
