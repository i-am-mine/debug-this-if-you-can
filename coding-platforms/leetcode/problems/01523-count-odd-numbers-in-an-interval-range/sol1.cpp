#include "../header/solution_interface.h"
using namespace std;

int countOdds(int low, int high) {
    return (high+1)/2 - low/2;
}
