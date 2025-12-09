#include "../header/solution_interface.h"
using namespace std;

int specialTriplets(vector<int>& nums) {
    unordered_map<long long,int> leftCount;
    unordered_map<long long,int> rightCount;
    for (long long x : nums) {
        rightCount[x]++;
    }

    long long result = 0;
    const long long MOD = 1000000007;

    for (long long x : nums) {
        rightCount[x]--;

        long long target = x * 2;
        long long left = 0, right = 0;
        if (leftCount.count(target)) left = leftCount[target];
        if (rightCount.count(target)) right = rightCount[target];

        result = (result + left * right % MOD) % MOD;

        leftCount[x]++;
    }

    return (int) result;
}
