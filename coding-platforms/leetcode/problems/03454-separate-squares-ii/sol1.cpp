#include "../header/solution_interface.h"
using namespace std;

double separateSquares(vector<vector<int>>& squares) {
    vector<tuple<long long,int,long long,long long>> events;
    vector<long long> xs;

    for (auto &s : squares) {
        long long x = s[0], y = s[1], l = s[2];
        events.push_back({y, 1, x, x + l});
        events.push_back({y + l, -1, x, x + l});
        xs.push_back(x);
        xs.push_back(x + l);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    sort(events.begin(), events.end());

    int m = xs.size() - 1;
    vector<int> cnt(4 * m);
    vector<long long> cover(4 * m);

    function<void(int,int,int,int,int,int)> update =
    [&](int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            cnt[idx] += val;
        } else {
            int mid = (l + r) / 2;
            update(idx*2, l, mid, ql, qr, val);
            update(idx*2+1, mid, r, ql, qr, val);
        }
        if (cnt[idx] > 0)
            cover[idx] = xs[r] - xs[l];
        else if (l + 1 == r)
            cover[idx] = 0;
        else
            cover[idx] = cover[idx*2] + cover[idx*2+1];
    };

    long long total = 0;
    long long prevY = get<0>(events[0]);

    for (auto &[y, t, xl, xr] : events) {
        total += cover[1] * (y - prevY);
        prevY = y;
        int L = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
        int R = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
        update(1, 0, m, L, R, t);
    }

    double half = total / 2.0;

    fill(cnt.begin(), cnt.end(), 0);
    fill(cover.begin(), cover.end(), 0);

    long long cur = 0;
    prevY = get<0>(events[0]);

    for (auto &[y, t, xl, xr] : events) {
        long long dy = y - prevY;
        if (cover[1] > 0 && cur + cover[1] * dy >= half) {
            return prevY + (half - cur) / cover[1];
        }
        cur += cover[1] * dy;
        prevY = y;
        int L = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
        int R = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
        update(1, 0, m, L, R, t);
    }
    return prevY;
}
