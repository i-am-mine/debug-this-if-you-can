#include "../header/solution_interface.h"
using namespace std;

bool isOneBitCharacter(vector<int>& bits) {
    if (bits.size() == 1) return true;

    // the before-last bit is 0 (...00) => true
    if (bits[bits.size()-2] == 0) return true;
    int countOne = 1;

    // the before-last bit is 1 (...10):
    // number of consecutive 1 bits is even => true. Ex: 11110
    for(int i = bits.size()-3; i >= 0; --i){
        if (bits[i] == 1) countOne++;
        else break;
    }

    if (countOne % 2 == 0) return true;

    return false;
}
