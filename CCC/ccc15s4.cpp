#include <bits/stdc++.h>
#define int long long

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int K, N, M, A, B;
vector<tuple<int, int, int>> adj[2001];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
int dist[2001][201];

void dijkstra() {
    dist[A][0] = 0;
    pq.emplace(forward_as_tuple(0, A, 0));

    while (!pq.empty()) {
        const auto [d, u, w] = pq.top(); pq.pop();

        if (d > dist[u][w]) continue;

        for (const auto &[v, t, h] : adj[u]) {
            if (w + h >= K) continue;
            if (d + t < dist[v][w + h]) {
                dist[v][w + h] = d + t;
                pq.emplace(forward_as_tuple(d + t, v, w + h));
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
        for (int j = 0; j <= K; j++) {
            dist[i][j] = INT64_MAX;
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v, t, h; cin >> u >> v >> t >> h;
        adj[u].emplace_back(v, t, h);
        adj[v].emplace_back(u, t, h);
    }

    cin >> A >> B;

    dijkstra();

    int best = INT64_MAX;

    for (int i = 0; i <= K; i++) {
        best = min(best, dist[B][i]);
    }

    if (best == INT64_MAX) {
        cout << -1;
    } else {
        cout << best;
    }

    return 0;
}
