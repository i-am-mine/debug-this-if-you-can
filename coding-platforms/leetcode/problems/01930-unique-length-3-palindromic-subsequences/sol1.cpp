#include "../header/solution_interface.h"
using namespace std;

int countPalindromicSubsequence(string s) {
    vector<int> first(26, -1), last(26, -1);
    int n = s.size();

    // Record first and last index of each character
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (first[c] == -1) first[c] = i;
        last[c] = i;
    }

    int result = 0;

    // For each letter as the outer character
    for (int c = 0; c < 26; c++) {
        if (first[c] != -1 && last[c] != -1 && first[c] < last[c]) {
            // Track distinct characters between first and last
            vector<bool> seen(26, false);
            for (int i = first[c] + 1; i < last[c]; i++) {
                seen[s[i] - 'a'] = true;
            }
            result += count(seen.begin(), seen.end(), true);
        }
    }

    return result;
}
