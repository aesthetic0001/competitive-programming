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

int M, N, c[1000001], dis[1000001][2];
queue<PII> q;
unordered_set<int> graph[1000001];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &c[i]);
        dis[i][0] = INT32_MAX;
        dis[i][1] = INT32_MAX;
    }

    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        graph[c[a]].emplace(c[b]);
        graph[c[b]].emplace(c[a]);
    }

    dis[c[1]][graph[c[1]].size() >= 2 ? 1 : 0] = 0;
    q.em(mp(c[1], graph[c[1]].size() >= 2 ? 1 : 0));

    while (!q.empty()) {
        const auto [node, valid] = q.front(); q.pop();
        const int dist = dis[node][valid];
        int newValid = valid == 1 ? 1 : (graph[node].size() >= 2 ? 1 : 0);

        // printf("visit %d: dis %d, valid: %d\n", node, dist, valid);

        for (const auto &v : graph[node]) {
            if (dist + 1 < dis[v][newValid]) {
                dis[v][newValid] = dist + 1;
                q.em(mp(v, newValid));
            }
        }
    }

    if (dis[c[N]][1] != INT32_MAX) {
        printf("%d", dis[c[N]][1]);
    } else {
        printf("-1");
    }

    return 0;
}
