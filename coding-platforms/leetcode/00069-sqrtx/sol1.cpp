#include "../header/solution_interface.h"
using namespace std;

int mySqrt(int x) {

    if (x < 2) return x;

    int left, right, mid, check, ans;
    left = ans = 0;
    right = x/2;
    if (right > 46340) right = 46340;


    while (left <= right) {
        mid = left + (right - left) / 2;

        check = mid * mid;

        if (check > x) {
            right = mid - 1;
        }
        else if (check < x) {
            ans = mid;
            left = mid + 1;
        }
        else
            return mid;

    }


    return ans;

}
