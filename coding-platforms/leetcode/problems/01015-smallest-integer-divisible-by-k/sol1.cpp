#include "../header/solution_interface.h"
using namespace std;

int smallestRepunitDivByK(int k) {
    if (k == 1) return 1;
    if (k == 11) return 2;
    if (k % 2 == 0 || k % 5 == 0) return -1;
    int r = 0;
    for (int len = 1; len <= k; ++len) {
        r = (r * 10 + 1) % k;
        if (r == 0) return len;
    }

    return -1;
}
