#include "../header/solution_interface.h"
using namespace std;

int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, vector<int>> mapX;
    unordered_map<int, vector<int>> mapY;

    for (auto &b : buildings) {
        int x = b[0], y = b[1];
        mapX[x].push_back(y);
        mapY[y].push_back(x);
    }

    for (auto &p : mapX) {
        auto &vals = p.second;
        sort(vals.begin(), vals.end());
    }
    for (auto &p : mapY) {
        auto &vals = p.second;
        sort(vals.begin(), vals.end());
    }

    int ans = 0;
    for (auto &b : buildings) {
        int x = b[0], y = b[1];

        auto &rowYs = mapX[x];
        auto &colXs = mapY[y];

        bool hasLeftRight = (rowYs.front() < y && y < rowYs.back());
        bool hasUpDown = (colXs.front() < x && x < colXs.back());

        if (hasLeftRight && hasUpDown) {
            ans++;
        }
    }
    return ans;
}
