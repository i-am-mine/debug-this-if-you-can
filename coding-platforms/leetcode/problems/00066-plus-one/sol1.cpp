#include "../header/solution_interface.h"
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int i = digits.size() - 1;
    digits[i]++;

    while (i >= 0 && digits[i] >= 10) {

        digits[i] -= 10;

        i--;
        if (i < 0) {
            digits.insert(digits.begin(), {1});
            break;
        }
        else
            digits[i]++;
    }

    return digits;
}
