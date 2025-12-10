#include "../header/solution_interface.h"
using namespace std;

int countPermutations(vector<int>& complexity) {
    const long long MOD = 1000000007LL;
    int n = (int)complexity.size();
    if (n <= 1) return 1;

    for (int i = 1; i < n; ++i) {
        if (complexity[0] >= complexity[i]) return 0;
    }

    long long ans = 1;
    for (int i = 2; i <= n - 1; ++i) {
        ans = (ans * i) % MOD;
    }
    return (int)ans;
}
