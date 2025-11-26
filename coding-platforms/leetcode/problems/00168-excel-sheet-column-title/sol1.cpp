#include "../header/solution_interface.h"
using namespace std;

string convertToTitle(int columnNumber) {
    int r = -1, count = 0;
    string title = "";

    while (columnNumber > 0){

        r = columnNumber % 26;
        if (r == 0) r = 26;
        title.insert(title.begin(), (char)(r+64));

        columnNumber -= r;
        columnNumber /= 26;
    }

    return title;
}
