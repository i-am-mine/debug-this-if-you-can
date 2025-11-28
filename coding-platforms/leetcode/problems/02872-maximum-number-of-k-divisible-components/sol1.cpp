#include "../header/solution_interface.h"
using namespace std;

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector<vector<int>> g(n);
    for (auto &e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    vector<int> visited(n, 0);
    int result = 0;

    function<long long(int)> dfs = [&](int u) -> long long {
        visited[u] = 1;
        long long sum = values[u];

        for (int v : g[u]) {
            if (!visited[v]) {
                sum += dfs(v);
            }
        }

        if (sum % k == 0) {
            result++;
            return 0;
        }
        return sum % k;
    };

    dfs(0);
    return result;
}
