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

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}
