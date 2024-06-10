#include <bits/stdc++.h>
#include <cstdint>
#define int long long

using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

// ->first other node, -> second: length, -> third: cost
vector<tuple<int, int, int>> g[2001];
vector<tuple<int, int, int, int>> edges(2001);
int N, M, ans = 0;

int dijkstra(int u, int v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    long long dist[N + 1];
    for (int i = 0; i <= N; i++) {
        dist[i] = INT64_MAX;
    }
    dist[u] = 0;
    pq.push({0, u});
    while (!pq.empty()) {
        int node = pq.top().second; pq.pop();
        for (const auto &[adj, l, c] : g[node]) {
            if (dist[adj] > dist[node] + l) {
                dist[adj] = dist[node] + l;
                pq.push({dist[node] + l, adj});
            }
        }
    }

    return dist[v];
}

signed main() {
    // freopen("sample.in", "r", stdin);
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v, l, c; cin >> u >> v >> l >> c;
        g[u].emplace_back(v, l, c);
        g[v].emplace_back(u, l, c);
        edges[i] = {l, c, u, v};
        ans += c;
    }

    sort(edges.begin(), edges.end(), greater<>());

    for (const auto &[l, c, u, v] : edges) {
        g[u].erase(remove(g[u].begin(), g[u].end(), make_tuple(v, l, c)), g[u].end());
        g[v].erase(remove(g[v].begin(), g[v].end(), make_tuple(u, l, c)), g[v].end());
        const int dist = dijkstra(u, v);
        if (l >= dist) {
            // no need: faster or equal path possible
            ans -= c;
        } else {
            // keep
            g[u].emplace_back(v, l, c);
            g[v].emplace_back(u, l, c);
        }
    }

    cout << ans << "\n";

    return 0;
}
