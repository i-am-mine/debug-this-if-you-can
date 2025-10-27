#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1 <= s.length    <= 100
 */

int maxFreqSum(string s) {
    unordered_map<char, int> freq;
    int maxVowerFreq = 0, maxConsoFreq = 0;

    for(char c: s){
        freq[c]++;
        if (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i') {
            maxVowerFreq = max(maxVowerFreq, freq[c]);
        }
        else {
            maxConsoFreq = max(maxConsoFreq, freq[c]);
        }
    }

    return maxConsoFreq + maxVowerFreq;
}
