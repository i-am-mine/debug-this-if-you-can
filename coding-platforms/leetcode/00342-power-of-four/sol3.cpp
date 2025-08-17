#include "../header/solution_interface.h"
using namespace std;

// Constraints: -2^31 <= n <= 2^31 - 1

bool isPowerOfFour(int n){
    unordered_set<int> powerOfFour = {1, 4, 16, 64, 256, 1024, 4096,
                                    16384, 65536, 262144, 1048576, 4194304,
                                    16777216, 67108864, 268435456, 1073741824};

    return n > 0 && powerOfFour.count(n);
}


