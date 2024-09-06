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

int N, skibidi[501][500];
vector<int> graph[501];

bool bfs(int start, int dest) {
    bool vis[501];
    queue<int> q;

    for (int i = 1; i <= 500; i++) {
        vis[i] = false;
    }

    vis[start] = true;
    q.em(start);

    while (!q.empty() && !vis[dest]) {
        const auto top = q.front(); q.pop();
        for (const auto &other : graph[top]) {
            if (!vis[other]) {
                vis[other] = true;
                q.em(other);
            }
        }
    }


    return vis[dest];
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int v;
        bool over = false;
        for (int j = 0; j < N; j++) {
            scanf("%d", &v);
            skibidi[i][j] = v;
            if (over) continue;
            if (v == i) {
                over = true;
                continue;
            }
            graph[i].eb(v);
        }
    }

    for (int i = 1; i <= N; i++) {
        int ans = i;
        int ct = 0;

        while (skibidi[i][ct] != i) {
            if (bfs(i, skibidi[i][ct]) && bfs(skibidi[i][ct], i)) {
                ans = skibidi[i][ct];
                break;
            }
            ct++;
        }

        printf("%d\n", ans);
    }

    return 0;
}
