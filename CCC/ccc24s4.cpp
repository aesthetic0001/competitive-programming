#include <cstring>
#include <iostream>
#include <vector>
#define MAX 200000

using namespace std;

int ans[MAX + 1];
bool vis[MAX + 1];

// .first -> the other node .second -> index i of the road
vector<vector<pair<int, int>>> t(MAX + 1);

inline void dfs(const int n, const bool red) {
    if (vis[n]) {
        return;
    }
    vis[n] = true;
    for (const auto &v : t[n]) {
        if (!vis[v.first]) {
            ans[v.second] = red ? 1 : 2;
            dfs(v.first, !red);
        }
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, M; cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        t[u].emplace_back(v, i);
        t[v].emplace_back(u, i);
    }

    for (int i = 0; i < N; i++) {
        dfs(i, true);
    }

    for (int i = 0; i < M; i++) {
        switch (ans[i]) {
            case 0: {
                cout << "G";
                break;
            }
            case 1: {
                cout << "R";
                break;
            }
            case 2: {
                cout << "B";
                break;
            }
        }
    }

    return 0;
}
