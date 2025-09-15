#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1 <= text.length <= 104
 * 0 <= brokenLetters.length <= 26
 */

int canBeTypedWords(string text, string brokenLetters) {
    int nWords = 0;
    bool isBroken = false;
    unordered_set<char> brokenLettersSet;

    for(char c: brokenLetters){
        brokenLettersSet.insert(c);
    }

    for(char c: text){
        if (!isBroken) {
            if (brokenLettersSet.count(c)) {
                isBroken = true;
            }
        }

        if (c == ' ') {
            if (!isBroken) {
                nWords++;
            }
            else {
                isBroken = false;
            }

        }
    }
    if (!isBroken) {
        nWords++;
    }

    return nWords;
}
