#include "../header/solution_interface.h"
using namespace std;

int countTriples(int n) {
    int count = 0, c0 = 0;
    int m_limit = (int)sqrt(n);

    for (int m = 2; m <= m_limit; ++m) {
        for (int k = 1; k < m; ++k) {
            if (((m - k) & 1) == 0) continue;
            if (gcd(m, k) != 1) continue;
            c0 = m*m + k*k;
            if (c0 > n) continue;
            count += n / c0;
        }
    }
    return count*2;
}
