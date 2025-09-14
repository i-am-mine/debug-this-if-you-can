#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1 <= x, y, z <= 100
 */

int findClosest(int x, int y, int z) {
    int d = (x - y) * (x + y - 2 * z);
    return (d != 0) << (d > 0);
}
