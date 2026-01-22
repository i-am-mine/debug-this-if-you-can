#include "../header/solution_interface.h"
using namespace std;

int minimumPairRemoval(vector<int>& nums) {
    int ans = 0;

    // Check if the array is non-decreasing
    auto isSorted = [&](const vector<int>& arr) {
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] < arr[i-1]) return false;
        }
        return true;
    };

    while (!isSorted(nums)) {
        int bestIdx = 0;
        int bestSum = nums[0] + nums[1];
        int n = nums.size();

        // Find the adjacent pair with minimum sum
        for (int i = 1; i < n - 1; i++) {
            int sum = nums[i] + nums[i+1];
            if (sum < bestSum) {
                bestSum = sum;
                bestIdx = i;
            }
        }

        // Merge the best pair
        nums[bestIdx] = bestSum;
        nums.erase(nums.begin() + bestIdx + 1);
        ans++;
    }

    return ans;
}
