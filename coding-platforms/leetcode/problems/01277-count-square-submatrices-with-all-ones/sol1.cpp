#include "../header/solution_interface.h"
using namespace std;

/* Constraints:
 * 1 <= arr.length    <= 300
 * 1 <= arr[0].length <= 300
 * 0 <= arr[i][j]     <= 1
 */

int countSquares(vector<vector<int>>& matrix) {
    int count = 0, squareLength = 1;
    bool isSquare = false;

    for(int i = 0; i < matrix.size(); i++){

        for(int j = 0; j < matrix[i].size(); j++){

            if(matrix[i][j] == 1) count++;

            squareLength = 1;

            // check square of length squareLength
            while (i+squareLength < matrix.size() && j+squareLength < matrix[i].size()){

                isSquare = true;

                for(int iSquare = i; iSquare <= i+squareLength; iSquare++) {
                    for(int jSquare = j; jSquare <= j+squareLength; jSquare++) {

                        if (matrix[iSquare][jSquare] == 0) {
                            isSquare = false;
                            break;
                        }
                    }
                    if (!isSquare) break;
                }

                if (isSquare) count++;

                squareLength++;
            }
        }
    }

    return count;
}
