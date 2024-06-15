#include <bits/stdc++.h>
#define int long long

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int K, N, M, A, B;
vector<tuple<int, int, int>> adj[2001];
priority_queue<pair<int, int>> pq;
int dist[2001];

void dijkstra() {
    dist[A] = 0;
    pq.push({0, A});

    while (!pq.empty()) {
        const auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (const auto &[v, t, h] : adj[u]) {
            if (h > 0) continue;
            if (d + t < dist[v]) {
                dist[v] = d + t;
                pq.push({dist[v], v});
            }
        }
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    // 1st subtask: K = 1, that is to say we cannot take any path that wears down the ship at all
    // literally just dijkstra
    cin >> K >> N >> M;

    for (int i = 1; i <= N; i++) {
        dist[i] = INT64_MAX;
    }

    for (int i = 0; i < M; i++) {
        int u, v, t, h; cin >> u >> v >> t >> h;
        adj[u].emplace_back(v, t, h);
        adj[v].emplace_back(u, t, h);
    }

    cin >> A >> B;

    dijkstra();

    if (dist[B] == INT64_MAX) {
        cout << 1;
    } else {
        cout << dist[B];
    }


    return 0;
}
