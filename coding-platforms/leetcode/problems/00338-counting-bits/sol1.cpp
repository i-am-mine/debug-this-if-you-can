#include "../header/solution_interface.h"
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n+1, 0);
    int lb {2}, ub = lb*2, num{0};

    for(int i = 1; i <= n; i++){
        if (i == 1) ans[i] = 1;
        else {
            if (i == ub) {
                lb *= 2;
                ub *= 2;
            }

            num = i;
            if (i > lb && i < ub) {
                num = i - lb;
                ans[i] = ans[lb];
            }
            while(num > 0){
                ans[i] += num % 2;
                num /= 2;
            }
        }
    }

    return ans;
}
