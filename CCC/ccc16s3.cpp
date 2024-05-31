#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#include <stack>
#include <cmath>

using namespace std;

#define MAX 100000

// adj list
vector<int> t[MAX];
// stores all leaves of the tree
queue<int> q;
// whether or not some node is confirmed to not be a dependency
bool cleared[MAX];
unordered_set<int> pho;

stack<int> diameter;
unordered_set<int> vis;

// best.first -> distance; best.second -> node

inline void dfs(int node, pair<int, int> &best) {
    if (vis.find(node) != vis.end()) return;

    diameter.emplace(node);

    vis.emplace(node);

    if (diameter.size() - 1 > best.first) {
        best.first = diameter.size() - 1;
        best.second = node;
    }

    for (const auto &v : t[node]) {
        if (vis.find(v) != vis.end()) continue;
        dfs(v, best);
    }

    diameter.pop();
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    int N, M; cin >> N >> M;

    int diameterStart, remEdges = N - 1;

    for (int i = 0; i < M; i++) {
        int d; cin >> d;
        pho.emplace(d);
        diameterStart = d;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        t[a].emplace_back(b);
        t[b].emplace_back(a);
    }

    for (int i = 0; i < N; i++) {
        if (t[i].size() == 1) q.push(i);
    }

    while (!q.empty()) {
        int leaf = q.front(); q.pop();

        if (cleared[leaf]) continue;

        // check if there are any neighbors that have been cleared and thus are able to be pruned
        for (const auto &v : t[leaf]) {
            if (cleared[v]) {
                // dont need to subtract here because it was removed already for the other side of the adjacency list.
                // simply removing it from this side as well because it is undirected graph
                t[leaf].erase(remove(t[leaf].begin(), t[leaf].end(), v), t[leaf].end());
            }
        }

        // determine whether or not this leaf node can be cleared
        if (t[leaf].size() == 1 && pho.find(leaf) == pho.end()) {
            q.push(t[leaf][0]);
            cleared[leaf] = true;
            t[leaf].erase(remove(t[leaf].begin(), t[leaf].end(), t[leaf][0]), t[leaf].end());
            remEdges--;
        }
    }

    // compute the diameter of the tree
    pair<int, int> one = make_pair(0, 0);
    dfs(diameterStart, one);
    vis.clear();
    pair<int, int> two = make_pair(0, 0);
    dfs(one.second, two);

    // cout << diameterStart << " " << one.second << " " << two.second << "\n";

    // diameter is longest and thus optimal path that we can take
    // however, there might still be remaining edges that were not visited. these would be visited twice, as it would need to go back to the node then back to main path after
    // cout << remEdges << "\n";
    cout << 2 * (remEdges - two.first) + (two.first);

    return 0;
}
