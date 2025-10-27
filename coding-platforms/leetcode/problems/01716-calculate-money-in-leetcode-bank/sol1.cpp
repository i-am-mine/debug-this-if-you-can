#include "../header/solution_interface.h"
using namespace std;

int totalMoney(int n) {
    int quotient = n / 7;
    int sum = 7 * (4 * quotient + (quotient-1) * quotient / 2);

    sum += (quotient+1 + (n%7 + quotient)) * (n%7) / 2;

    return sum;
}
