#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, M, s, d, k; vector<int> tree[MAX]; bool pho[MAX];

inline bool dfs(int cur, int prev) {
    for (const auto &v : tree[cur]) {
        if (v == prev) continue;
        if (dfs(v, cur)) pho[cur] = true;
    }

    if (!pho[cur]) --s;

    return pho[cur];
}

inline void diameter(int node, int prev, int dist, pair<int, int> &best) {
    if (dist > best.second) {
        best.first = node;
        best.second = dist;
    }
    for (const auto &v : tree[node]) {
        if (v != prev && pho[v]) diameter(v, node, dist + 1, best);
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    scan(N); scan(M);

    for (int i = 0; i < M; i++) {
        scan(k);
        pho[k] = true;
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v; scan(u); scan(v);
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    s = N - 1;

    dfs(k, -1);

    pair<int, int> a = {0, -1}, b = {0, -1};

    diameter(k, -1, 0, a); diameter(a.first, -1, 0, b);

    cout << 2 * (s - b.second) + b.second;

    return 0;
}
