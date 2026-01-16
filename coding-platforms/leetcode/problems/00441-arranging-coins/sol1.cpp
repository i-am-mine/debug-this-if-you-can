#include "../header/solution_interface.h"
using namespace std;

int arrangeCoins(int n) {
    long long delta = 1 + 8 * static_cast<long long>(n);
    return static_cast<int>( 0.5 * (-1 + sqrt(delta)) );
}
