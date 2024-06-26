#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

// should be possible as long as no circular dependencies
// directed graph
// least dependencies, breaking ties by numerically smallest
// could use DP and add deps but its overkill for these constraints

vector<int> adj[8]; int deps[8]; bool complete[8];

bool calc_deps() {
    // calculate dependencies
    queue<int> bfs;
    for (int i = 1; i <= 7; i++) {
        if (complete[i]) continue;
        // cout << i << "\n";
        bfs.emplace(i);
        unordered_set<int> vis;
        while (!bfs.empty()) {
            const int u = bfs.front(); bfs.pop();

            if (vis.find(u) != vis.end()) {
                if (u == i) {
                    cout << "Cannot complete these tasks. Going to bed.";
                    return false;
                }
                continue;
            }

            vis.emplace(u);

            if (u != i) ++deps[i];

            for (const auto &v : adj[u]) {
                if (complete[v]) continue;
                bfs.emplace(v);
            }
        }
        // cout << i << ": " << deps[i] << " ";
    }
    // cout << "\n";
    return true;
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    adj[7].emplace_back(1);
    adj[4].emplace_back(1);
    adj[1].emplace_back(2);
    adj[4].emplace_back(3);
    adj[5].emplace_back(3);

    int u, v;

    while (true) {
        cin >> u >> v;
        if (!u || !v) break;
        adj[v].emplace_back(u);
    }

    const bool poss = calc_deps();

    if (!poss) return 0;

    for (int i = 0; i < 7; i++) {
        int best = INT32_MAX;
        int num = -1;

        for (int j = 1; j <= 7; j++) {
            if (complete[j]) continue;
            if (deps[j] == best) {
                num = min(num, j);
            } else if (deps[j] < best) {
                best = deps[j];
                num = j;
            }
        }

        for (int j = 1; j <= 7; j++) deps[j] = 0;

        cout << num << " ";
        complete[num] = true;
        calc_deps();
    }

    return 0;
}
