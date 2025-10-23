#include "../header/solution_interface.h"
using namespace std;

bool hasSameDigits(string s) {
    int n = s.size();
    while(n > 2) {
        for (int i = 0; i < n-1; ++i) {
            s[i] = ((s[i] + s[i+1] - 2*'0') % 10) + '0';
        }
        n--;
    }

    return s[0] == s[1];
}
