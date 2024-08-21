#include <bits/stdc++.h>

using namespace std;

unordered_set<int> adj[50] = {{}, {6}, {6}, {4,5,6,15}, {3,5,6}, {3,4,6}, {1,2,3,4,5,7}, {6,8}, {7,9}, {8,10,12}, {9,11}, {10,12}, {9,11,13}, {12,14,15}, {13}, {3,13}, {17,18}, {16,18}, {16,17}};
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

// alternatively just use bfs
int dijkstra(int x, int y) {
    int dist[50];
    for (int i = 0; i < 50; i++) {
        dist[i] = INT32_MAX;
    }

    dist[x] = 0;

    q.emplace(make_pair(0, x));

    while (!q.empty()) {
        const auto [d, node] = q.top(); q.pop();

        if (d > dist[node]) continue;

        for (const auto &neighbor : adj[node]) {
            if (dist[neighbor] > d + 1) {
                dist[neighbor] = d + 1;
                q.emplace(make_pair(d + 1, neighbor));
            }
        }
    }

    return dist[y];
}

signed main() {
    freopen("sample.in", "r", stdin);
    cin.tie(0); cin.sync_with_stdio(0);

    char ch;

    while (true) {
        cin >> ch;
        switch (ch) {
            case 'i': {
                int x, y; cin >> x >> y;
                if (adj[x].find(y) != adj[x].end()) continue;
                adj[x].emplace(y);
                adj[y].emplace(x);
                break;
            }
            case 'd': {
                int x, y; cin >> x >> y;
                if (adj[x].find(y) == adj[x].end()) continue;
                adj[x].erase(y);
                adj[y].erase(x);
                break;
            }
            case 'n': {
                int x; cin >> x;
                cout << adj[x].size() << "\n";
                break;
            }
            case 'f': {
                int x; cin >> x;
                // degree of sep. 2
                int ans = 0;
                unordered_set<int> counted;
                for (const int &direct : adj[x]) {
                    for (const int &indirect : adj[direct]) {
                        if (adj[x].find(indirect) == adj[x].end() && indirect != x && counted.find(indirect) == counted.end()) {
                            ans++;
                            counted.emplace(indirect);
                        }
                    }
                }
                cout << ans << "\n";
                break;
            }
            case 's': {
                int x, y; cin >> x >> y;
                int res = dijkstra(x, y);
                if (res == INT32_MAX) {
                    cout << "Not connected\n";
                } else {
                    cout << res << "\n";
                }
            }
            break;
        }
        if (ch == 'q') break;
    }

    return 0;
}
