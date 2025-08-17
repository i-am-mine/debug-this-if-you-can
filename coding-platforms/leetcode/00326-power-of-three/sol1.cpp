#include "../header/solution_interface.h"
using namespace std;

// Constraints: -2^31 <= n <= 2^31 - 1

bool isPowerOfThree(int n){

    if (n <= 0) return false;

    while (n > 1){
        if (n % 3 != 0) return false;
        n /= 3;
    }

    return true;
}
