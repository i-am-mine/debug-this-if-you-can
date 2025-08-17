#include "../header/solution_interface.h"
using namespace std;

// Constraints: -2^31 <= n <= 2^31 - 1

bool isPowerOfTwo(int n){

    if (n <= 0) return false;

    while (n > 1){
        if (n % 2 == 1) return false;
        n /= 2;
    }

    return true;


}
