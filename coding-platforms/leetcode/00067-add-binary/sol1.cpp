#include "../header/solution_interface.h"
using namespace std;

string addBinary(string a, string b) {
    if (a == "" || a == "0") return b;
    if (b == "" || b == "0") return a;

    string res = "";
    int ia = a.size()-1, ib = b.size()-1, i = 0;
    bool carry = 0;
    char *ptr = nullptr;

    while (ia >= 0 && ib >= 0){

        switch(a[ia] + b[ib] - 2*'0' + carry){
            case 0:
                res.insert(0, "0");
                break;

            case 1:
                res.insert(0, "1");
                carry = 0;
                break;

            case 2:
                res.insert(0, "0");
                carry = 1;
                break;

            case 3:
                res.insert(0, "1");
                carry = 1;
                break;

            default:
                break;
        }

        ia--;
        ib--;
    }

    if (ia < 0 && ib < 0) {
        i = -1;
    }
    else if (ia < 0 && ib >= 0){
        i = ib;
        ptr = &b[i];
    }
    else if (ib < 0 && ia >= 0){
        i = ia;
        ptr = &a[i];
    }

    while (i >= 0){
        switch(*ptr - '0' + carry){
            case 0:
                res.insert(0, "0");
                break;

            case 1:
                res.insert(0, "1");
                carry = 0;
                break;

            case 2:
                res.insert(0, "0");
                carry = 1;
                break;

            default:
                break;
        }

        i--;
        if (i >= 0) ptr--;
    }

    if (carry) res.insert(0, "1");

   return res;
}
