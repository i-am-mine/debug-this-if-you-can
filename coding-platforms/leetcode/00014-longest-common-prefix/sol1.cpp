#include "../header/solution_interface.h"
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 1) return strs[0];

    bool stop = false;
    string res = "";

    for (int i = 0; i < strs[0].size(); i++) {

        for (int j = 1; j < strs.size(); j++) {

            if (i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                stop = true;
                break;
            }
        }
        if (stop) break;
        else res += strs[0][i];
    }

    return res;

    return "";
}
