#include "../header/solution_interface.h"
using namespace std;

// Constraints: -2^31 <= n <= 2^31 - 1

bool isPowerOfThree(int n) {
    return n > 0 && 1162261467 % n == 0; // 3^19 = 1162261467
}
