#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 */

long long zeroFilledSubarray(vector<int>& nums) {
    long long result = 0, zeroSequenceLength = 0;

    for (int num : nums) {
        if (num == 0) {
            zeroSequenceLength++;
            result += zeroSequenceLength;    // result += 1 + 2 + 3 + ...
        }
        else {
            zeroSequenceLength = 0;
        }
    }

    return result;
}
