#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1 <= x, y, z <= 100
 */

int findClosest(int x, int y, int z) {
    if (abs(z-x) < abs(z-y)) return 1;
    if (abs(z-x) > abs(z-y)) return 2;
    return 0;
}
