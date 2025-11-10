#include "../header/solution_interface.h"
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> checkS;

    for (char c: s) checkS[c]++;

    for (char c: t) {
        if (!checkS[c]) return false;
        else {
            checkS[c]--;
            if (checkS[c] == 0) checkS.erase(c);
        }
    }

    if (checkS.size() > 0) return false;

    return true;
}
