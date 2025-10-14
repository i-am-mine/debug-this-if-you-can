#include "../header/solution_interface.h"
using namespace std;

bool isValid(string s) {
    if (s.size() == 1) return false;

    stack<char> box;
    char close;

    for (char c: s){
        if(c == '(' || c == '[' || c == '{') box.push(c);
        else {
            if (box.empty()) return false;
            close = box.top();
            box.pop();
            if ((close == '(' && c != ')') ||
                (close == '[' && c != ']') ||
                (close == '{' && c != '}')) {
                    return false;
            }
        }
    }

    if (!box.empty()) return false;

    return true;

}
