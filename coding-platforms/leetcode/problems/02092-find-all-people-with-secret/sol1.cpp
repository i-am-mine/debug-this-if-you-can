#include "../header/solution_interface.h"
using namespace std;

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    vector<bool> know(n, false);
    know[0] = know[firstPerson] = true;

    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });

    int m = meetings.size();

    for (int i = 0; i < m; ) {
        int time = meetings[i][2];

        // collect persons in this time
        unordered_map<int, int> id;
        vector<pair<int,int>> edges;

        int j = i;
        while (j < m && meetings[j][2] == time) {
            int x = meetings[j][0];
            int y = meetings[j][1];

            if (!id.count(x)) id[x] = id.size();
            if (!id.count(y)) id[y] = id.size();

            edges.push_back({x, y});
            j++;
        }

        int k = id.size();
        vector<int> parent(k);
        for (int t = 0; t < k; t++) parent[t] = t;

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[b] = a;
        };

        // union
        for (auto &e : edges) {
            unite(id[e.first], id[e.second]);
        }

        // mark components having secret
        vector<bool> hasSecret(k, false);
        for (auto &p : id) {
            if (know[p.first]) {
                hasSecret[find(p.second)] = true;
            }
        }

        // update know
        for (auto &p : id) {
            if (hasSecret[find(p.second)]) {
                know[p.first] = true;
            }
        }

        i = j;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (know[i]) ans.push_back(i);
    }
    return ans;
}
