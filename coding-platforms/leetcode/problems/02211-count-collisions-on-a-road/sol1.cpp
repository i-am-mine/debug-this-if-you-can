#include "../header/solution_interface.h"
using namespace std;

int countCollisions(string directions) {
    if (directions.size() == 1) return 0;

    int countColli, sameDirection, i;
    countColli = sameDirection = i = 0;

    // ignore the case starting with "LLL...."
    while(directions[i] == 'L'){
        i++;
    }

    for(; i < directions.size()-1; ++i){
        char &first = directions[i];
        char &second = directions[i+1];

        if (first == 'R') {
            switch(second) {
                case 'L':
                    countColli += 2 + sameDirection;
                    second = 'S';
                    sameDirection = 0;
                    break;

                case 'S':
                    countColli += 1 + sameDirection;
                    sameDirection = 0;
                    break;

                case 'R':
                    sameDirection++;
                    break;
                default:
            }
        }
        else if (first == 'S' && second == 'L') {
            countColli += 1 + sameDirection;
            second = 'S';
            sameDirection = 0;
        }
        else if (first == 'L' && second == 'L') {
            sameDirection++;
        }
    }

    return countColli;
}
