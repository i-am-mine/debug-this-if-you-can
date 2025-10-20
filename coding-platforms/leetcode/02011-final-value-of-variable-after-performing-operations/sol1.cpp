#include "../header/solution_interface.h"
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    int countPlus = 0;
    for(const string &s: operations) {
        if (s[1] == '+') {
            countPlus++;
        }
        else {
            countPlus--;
        }

    }

    return countPlus;
}
