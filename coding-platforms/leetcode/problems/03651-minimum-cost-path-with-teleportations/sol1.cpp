#include "../header/solution_interface.h"
using namespace std;

int minCost(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    const int INF = 1e9;

    // Store all cells as (value, row, col) to process teleports efficiently
    vector<tuple<int, int, int>> cells;
    cells.reserve(m * n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cells.emplace_back(grid[i][j], i, j);
        }
    }

    // Sort descending: allows us to efficiently find the min cost
    // among all valid teleport sources (val >= target_val)
    sort(cells.rbegin(), cells.rend());

    // dp[t][i][j] = min cost to reach (i, j) using t teleports
    vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m, vector<int>(n, INF)));

    // Base case: Start at (0,0) with 0 cost
    dp[0][0][0] = 0;

    for (int t = 0; t <= k; ++t) {
        // 1. Propagate Normal Moves (Right/Down) in current layer t
        // Since moves are only Right/Down, we can iterate sequentially.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[t][i][j] == INF) continue;

                // Move Down
                if (i + 1 < m) {
                    dp[t][i+1][j] = min(dp[t][i+1][j], dp[t][i][j] + grid[i+1][j]);
                }
                // Move Right
                if (j + 1 < n) {
                    dp[t][i][j+1] = min(dp[t][i][j+1], dp[t][i][j] + grid[i][j+1]);
                }
            }
        }

        // 2. Propagate Teleports to layer t+1
        if (t < k) {
            int min_so_far = INF;
            int idx = 0;
            while (idx < cells.size()) {
                int val = get<0>(cells[idx]);
                int start = idx;
                int group_min = INF;

                // Process all cells with the SAME value together
                // 1. Find the best source cost among this group in the current layer
                while (idx < cells.size() && get<0>(cells[idx]) == val) {
                    auto [v, r, c] = cells[idx];
                    group_min = min(group_min, dp[t][r][c]);
                    idx++;
                }

                // 2. Update global min source (includes all cells with value > val AND == val)
                min_so_far = min(min_so_far, group_min);

                // 3. Apply teleport: Any cell in this group can be a destination
                // from any cell with value >= val (captured in min_so_far)
                for (int p = start; p < idx; ++p) {
                    auto [v, r, c] = cells[p];
                    dp[t+1][r][c] = min(dp[t+1][r][c], min_so_far);
                }
            }
        }
    }

    // Result is the min cost to reach (m-1, n-1) across all k layers
    int ans = INF;
    for (int t = 0; t <= k; ++t) {
        ans = min(ans, dp[t][m-1][n-1]);
    }
    return ans;
}
