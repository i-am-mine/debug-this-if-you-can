#include "../header/solution_interface.h"
using namespace std;

int titleToNumber(string columnTitle) {

    int res = 0, coef = 1;

    for (int i = columnTitle.size()-1; i >= 0; i--){

        res += (columnTitle[i] - 'A' + 1)*coef;
        if (i > 0) coef *= 26;
    }


    return res;
}
