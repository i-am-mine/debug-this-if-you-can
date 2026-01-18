#include "../header/solution_interface.h"
using namespace std;

string addStrings(string num1, string num2) {
    if (num1 == "0") return num2;
    if (num2 == "0") return num1;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    string res;
    res.reserve(max( num1.size(), num2.size() ));

    int i = 0, q = 0;
    while(1){
        if (i >= num1.size() && i >= num2.size() && q == 0) break;

        if (i < num1.size()) {
            q += num1[i] - '0';
        }

        if (i < num2.size()) {
            q += num2[i] - '0';
        }

        res.push_back((q % 10) + '0');
        q /= 10;

        i++;
    }

    reverse(res.begin(), res.end());

    return res;
}
