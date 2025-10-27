#include "../header/solution_interface.h"
using namespace std;

// Constraints: -2^31 <= n <= 2^31 - 1

bool isPowerOfFour(int n) {
    return n > 0 &&
            (n & (n-1)) == 0 && // power of 2
            (n & 0x55555555) != 0; // the 1-bit is in odd position, and 0x5555555 = ...01 0101
}
