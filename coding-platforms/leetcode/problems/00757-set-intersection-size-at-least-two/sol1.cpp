#include "../header/solution_interface.h"
using namespace std;

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) {
             if (a[1] == b[1]) return a[0] > b[0];
             return a[1] < b[1];
         });

    int p1 = -1, p2 = -1;  // last two selected points (p1 < p2)
    int result = 0;

    for (auto& it : intervals) {
        int start = it[0], end = it[1];

        if (start <= p1) {
            // Both p1 and p2 are inside => nothing to add
            continue;
        }
        else if (start <= p2) {
            // Only p2 is inside => add one new point: end
            result += 1;
            p1 = p2;
            p2 = end;
        }
        else {
            // Neither inside => add two: end-1 and end
            result += 2;
            p1 = end - 1;
            p2 = end;
        }
    }

    return result;
}
