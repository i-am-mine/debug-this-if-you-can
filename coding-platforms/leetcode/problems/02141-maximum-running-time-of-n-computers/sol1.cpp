#include "../header/solution_interface.h"
using namespace std;

long long maxRunTime(int n, vector<int>& batteries) {
    long long left = 0;
    long long right = 0;
    for (long long b : batteries) right += b;

    right /= n; // maximum possible T

    auto canRun = [&](long long T) {
        long long total = 0;
        for (long long b : batteries) {
            total += min(b, T);
        }
        return total >= T * n;
    };

    while (left < right) {
        long long mid = (left + right + 1) / 2;
        if (canRun(mid)) left = mid;
        else right = mid - 1;
    }

    return left;
}
