#include "../header/solution_interface.h"
using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    const long long MOD = 1000000007;
    unordered_map<long long, long long> cnt;  // map y -> count of points at that y

    for (auto &p : points) {
        long long y = p[1];
        cnt[y]++;
    }

    long long result = 0;
    long long prevPairs = 0;

    for (auto & [y, c] : cnt) {
        if (c < 2) continue;
        long long curPairs = c * (c - 1) / 2;
        // combine with all previous pairs to form trapezoids
        result = (result + prevPairs * curPairs) % MOD;
        prevPairs = (prevPairs + curPairs) % MOD;
    }

    return (int)result;
}
