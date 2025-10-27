#include "../header/solution_interface.h"
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<char> seen;
    char c = 'a';

    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            c = board[i][j];
            if (c == '.') continue;
            else if ( c < '1' || c > '9' || seen.count(c))
                return false;
            seen.insert(c);
        }
        seen.clear();
    }


    for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            c = board[j][i];
            if (c == '.') continue;
            else if ( c < '1' || c > '9' || seen.count(c))
                return false;
            seen.insert(c);
        }
        seen.clear();
    }

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    c = board[i*3+k][j*3+l];
                    if (c == '.') continue;
                    else if ( c < '1' || c > '9' || seen.count(c))
                        return false;
                    seen.insert(c);
                }
            }
            seen.clear();
        }
    }


    return true;
}
