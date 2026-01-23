#include "../header/solution_interface.h"
using namespace std;

int minimumPairRemovalii(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    // Use long long for values as sums can exceed integer limits
    vector<long long> vals(nums.begin(), nums.end());

    // Doubly Linked List simulation
    vector<int> next(n), prev(n);
    for (int i = 0; i < n; ++i) {
        next[i] = i + 1;
        prev[i] = i - 1;
    }

    // Set stores pairs {sum, index}
    // index represents the pair (index, next[index])
    set<pair<long long, int>> min_pairs;

    // Count inversions (where val[i] > val[next[i]])
    int inversions_count = 0;

    auto is_inverted = [&](int i) {
        int j = next[i];
        if (j >= n) return false; // End of list
        return vals[i] > vals[j];
    };

    // Initial population
    for (int i = 0; i < n - 1; ++i) {
        min_pairs.insert({vals[i] + vals[i + 1], i});
        if (vals[i] > vals[i + 1]) {
            inversions_count++;
        }
    }

    int ops = 0;

    while (inversions_count > 0) {
        ops++;

        // 1. Get the pair to merge
        // The set is sorted by sum, then by index, satisfying the "leftmost" requirement.
        auto it = min_pairs.begin();
        long long current_sum = it->first;
        int u = it->second;
        int v = next[u]; // The right neighbor being merged

        // 2. Remove old relations involving u and v
        min_pairs.erase(it); // Remove the pair (u, v) itself

        // Remove pair (prev[u], u) if it exists
        int p = prev[u];
        if (p != -1) {
            min_pairs.erase({vals[p] + vals[u], p});
            if (vals[p] > vals[u]) inversions_count--;
        }

        // Remove pair (v, next[v]) if it exists
        int last = next[v];
        if (last < n) {
            min_pairs.erase({vals[v] + vals[last], v});
            if (vals[v] > vals[last]) inversions_count--;
        }

        // Remove inversion count for the merged pair (u, v)
        if (vals[u] > vals[v]) inversions_count--;

        // 3. Perform Merge
        vals[u] = vals[u] + vals[v]; // u becomes the merged node

        // Update pointers to skip v
        next[u] = last;
        if (last < n) {
            prev[last] = u;
        }
        // v is now effectively removed, we don't need to update prev[v] or next[v]

        // 4. Add new relations
        // Add pair (prev[u], u_new)
        if (p != -1) {
            min_pairs.insert({vals[p] + vals[u], p});
            if (vals[p] > vals[u]) inversions_count++;
        }

        // Add pair (u_new, next[u]) which is (u, last)
        if (last < n) {
            min_pairs.insert({vals[u] + vals[last], u});
            if (vals[u] > vals[last]) inversions_count++;
        }
    }

    return ops;
}
