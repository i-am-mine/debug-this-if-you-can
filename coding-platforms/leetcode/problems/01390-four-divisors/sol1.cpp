#include "../header/solution_interface.h"
using namespace std;

int sumFourDivisors(vector<int>& nums) {
    int ans = 0;

    for (int num : nums) {
        vector<int> divisors;

        for (int d = 1; d * d <= num; d++) {
            if (num % d == 0) {
                divisors.push_back(d);
                if (d * d != num)
                    divisors.push_back(num / d);
                if (divisors.size() > 4)
                    break;
            }
        }

        if (divisors.size() == 4) {
            for (int d : divisors)
                ans += d;
        }
    }
    return ans;
}
