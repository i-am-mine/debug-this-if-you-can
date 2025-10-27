#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 */

long long zeroFilledSubarray(vector<int>& nums) {
    long long result = 0, zeroSequenceLength = 0;

    for(int i = nums.size()-1; i >= 0; i--){
        if (nums[i] == 0) {
            zeroSequenceLength++;
        }

        if (i == 0 || nums[i] != 0) {
            result += zeroSequenceLength * (zeroSequenceLength + 1);
            zeroSequenceLength = 0;
        }
    }

    return result/2;
}
