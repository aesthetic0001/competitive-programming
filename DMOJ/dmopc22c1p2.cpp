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

int M, N, ans = INT32_MAX, c[1000001], dis[1000001], dis2[1000001];
PII first[1000001], second[1000001];
queue<int> q;
vector<int> graph[1000001];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%d", &c[i]);
        dis[i] = INT32_MAX;
        dis2[i] = INT32_MAX;
        first[i] = mp(0, INT32_MAX);
        second[i] = mp(0, INT32_MAX);
    }

    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        graph[a].eb(b);
        graph[b].eb(a);
    }

    // idea: get all nodes from N, find closest colors and second colors, then final bfs from 1 to compare distance
    q.em(N);
    dis[N] = 0;

    while (!q.empty()) {
        const int top = q.front(); q.pop();

        if (first[c[top]].first == 0) {
            // best distance found
            first[c[top]] = mp(top, dis[top]);
        } else if (second[c[top]].first == 0) {
            // second best distance
            second[c[top]] = mp(top, dis[top]);
        }

        for (const auto &adj : graph[top]) {
            if (dis[top] + 1 < dis[adj]) {
                dis[adj] = dis[top] + 1;
                q.em(adj);
            }
        }
    }

    // final bfs from 1
    q.em(1);
    dis2[1] = 0;

    while (!q.empty()) {
        const int top = q.front(); q.pop();

        const int color = c[top];

        if (first[color].first != 0) {
            if (first[color].first != top) {
                // best case for this color
                ans = min(ans, first[color].second + dis2[top]);
            }
        }

        for (const auto &adj : graph[top]) {
            if (dis2[top] + 1 < dis2[adj]) {
                dis2[adj] = dis2[top] + 1;
                q.em(adj);
            }
        }
    }

    printf("%d", (ans == INT32_MAX ? -1 : ans));

    return 0;
}
