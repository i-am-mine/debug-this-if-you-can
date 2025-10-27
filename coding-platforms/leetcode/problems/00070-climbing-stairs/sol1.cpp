#include "../header/solution_interface.h"
using namespace std;

int climbStairs(int n) {

    if (n <= 3) return n;

    int count = 0, a = 2, b = 3;

    for (int i = 4; i <= n; i++){

        count = a + b;
        a = b;
        b = count;

    }

    return count;
}
