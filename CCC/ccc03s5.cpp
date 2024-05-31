#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define C_MAX 10000

using namespace std;

unordered_set<int> dest;

bool vis[C_MAX + 1];

// pair first: w, pair second: other node
vector<vector<pair<int, int>>> t(C_MAX + 1);
priority_queue<pair<int, int>> q;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int C, R, D; cin >> C >> R >> D;

    for (int i = 0; i < R; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        t[x].emplace_back(w, y);
        t[y].emplace_back(w, x);
    }

    for (int i = 0; i < D; i++) {
        int d;
        cin >> d;
        dest.emplace(d);
    }

// You can assume that you are starting in city 1 and that city 1 is not a destination city. You can visit the d destination cities in any order, but you must visit all d destination cities.
    q.push({INT_MAX, 1});

    int max = INT_MAX;

    while (!q.empty() && !dest.empty()) {
        const auto best = q.top();

        max = min(best.first, max);

        if (dest.find(best.second) != dest.end()) {
            dest.erase(best.second);
        }

        vis[best.second] = true;

        q.pop();

        for (const auto &u : t[best.second]) {
            if (vis[u.second]) continue;
            q.push(u);
        }
    }

    cout << max;

    return 0;
}
