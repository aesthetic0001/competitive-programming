#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N, R, X, Y, ans = INT32_MAX, dis[200001];
bool vis1[200001];
unordered_set<int> path, rabbits;
vector<int> adj[200001];

bool dfs1(int node) {
    // printf("vis: %d\n", node);
    bool good = node == Y;
    vis1[node] = true;
    for (const auto &b : adj[node]) {
        // printf("adj: %d\n", b);
        if (!vis1[b]) {
            good = good || dfs1(b);
        }
    }
    if (good) {
        // printf("backtrack: %d\n", node);
        path.em(node);
        dis[node] = 0;
    }
    return good;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &R);

    for (int i = 1; i <= N; i++) {
        dis[i] = INT32_MAX;
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b; scanf("%d %d", &a, &b);
        adj[a].eb(b);
        adj[b].eb(a);
    }

    for (int i = 0; i < R; i++) {
        int a; scanf("%d", &a);
        rabbits.em(a);
    }

    scanf("%d %d", &X, &Y);

    // find pth
    dfs1(X);

    // for (const auto &v : path) {
    //     printf("%d\n", v);
    // }

    // bfs for ans
    queue<int> q;
    for (const auto &a : path) {
        q.em(a);

        while (!q.empty()) {
            const auto top = q.front(); q.pop();
            for (const auto &b : adj[top]) {
                if (dis[top] + 1 < dis[b]) {
                    dis[b] = dis[top] + 1;
                    q.em(b);
                }
            }
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     printf("val at %d: %d\n", i, dis[i]);
    // }

    for (const auto &rabbit : rabbits) {
        ans = min(dis[rabbit], ans);
    }

    printf("%d", ans);

    return 0;
}
