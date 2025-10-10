#include "../header/solution_interface.h"
using namespace std;

vector<int> getNoZeroIntegers(int n) {
    int numA, numB;
    for(int i = 1; i < n; i++){
        numA = i;
        numB = n - i;
        while(numA > 0 || numB > 0){
            if (numA > 0 && numA % 10 == 0) {
                break;
            }
            if (numB > 0 && numB % 10 == 0) {
                break;
            }
            numA /= 10;
            numB /= 10;
        }
        if (numA == 0 && numB == 0) {
            return {i, n - i};
        }
    }

    return {1,1};
}
