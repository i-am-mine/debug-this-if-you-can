#include "../header/solution_interface.h"
using namespace std;

// Constraints: -2^31 <= n <= 2^31 - 1

bool isPowerOfTwo(int n){
    return n <= 0 ? false : 1073741824 % n == 0; // 2^30 = 1073741824
}
