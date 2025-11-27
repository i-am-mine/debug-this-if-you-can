#include "../header/solution_interface.h"
using namespace std;

long long maxSubarraySum(vector<int>& nums, int k) {

    long long ans = LLONG_MIN;
    long long prefix = 0;
    // minPref[r] = minimum prefix sum seen so far at indices with index % k == r
    vector<long long> minPref(k, LLONG_MAX / 2);
    // To handle subarray starting at index 0
    minPref[(0 - 1 + k) % k] = 0;
    // Equivalently many implementations set minPref[k-1] = 0

    for (int i = 0; i < (int)nums.size(); i++) {
        prefix += nums[i];
        int r = i % k;
        ans = max(ans, prefix - minPref[r]);
        minPref[r] = min(minPref[r], prefix);
    }
    return ans;
}
