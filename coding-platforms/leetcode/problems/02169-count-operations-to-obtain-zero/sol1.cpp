#include "../header/solution_interface.h"
using namespace std;

int countOperations(int num1, int num2) {
    int count = 0;

    while(num1 > 0 && num2 > 0) {
        if (num1 == num2) return count + 1;
        if (num1 == 1) return count + num2;
        if (num2 == 1) return count + num1;
        if (num2 - num1 == 1) return count + num2;
        if (num1 - num2 == 1) return count + num1;

        if (num1 > num2) num1 -= num2;
        else num2 -= num1;

        count++;
    }

    return count;
}
