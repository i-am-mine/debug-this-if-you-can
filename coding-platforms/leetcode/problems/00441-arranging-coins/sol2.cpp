#include "../header/solution_interface.h"
using namespace std;

int arrangeCoins(int n) {
    return static_cast<int> ( -0.5 + sqrt(2) * sqrt(0.125 + n) );
}
