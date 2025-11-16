#include "../header/solution_interface.h"
using namespace std;

int numSub(string s) {
    long long nSubStr = 0;
    int countOne = 0;

    for(char c: s){
        if (c == '1') {
            countOne++;
        }
        else {
            nSubStr += static_cast<long long>(countOne)*(countOne+1)/2;
            countOne = 0;
        }
    }

    if (countOne > 0) {
        nSubStr += static_cast<long long>(countOne)*(countOne+1)/2;
    }

    return static_cast<int>(nSubStr % static_cast<long long>(1e9+7));
}
