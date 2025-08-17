#include "../header/solution_interface.h"
using namespace std;

// Constraints: -2^31 <= n <= 2^31 - 1

bool isPowerOfTwo(int n) {
    return n <= 0 ? false : (n & (n-1)) == 0; // n is power of 2 iff (n & (n-1)) == 0
}
