#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, p[500001], indeg[500001];
bool vis[500001];
vector<int> graph[500001];
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
      scanf("%d", &p[i]);
    }

    for (int i = 0; i < M; i++) {
      int u, v; scanf("%d %d", &u, &v);
      graph[v].emplace_back(u);
      indeg[u] += 1;
    }

    for (int i = 1; i <= N; i++) {
      if (indeg[i] == 0) {
        q.emplace(i);
        vis[i] = true;
      }
    }

    while (!q.empty()) {
      const auto top = q.front(); q.pop();

      for (const auto &adj : graph[top]) {
        if (vis[adj]) continue;
        indeg[adj] -= 1;
        if (indeg[adj] == 0 || p[adj]) {
          vis[adj] = true;
          q.emplace(adj);
        }
      }
    }

    for (int i = 1; i <= N; i++) {
      if (vis[i]) {
        printf("1");
      } else {
        printf("0");
      }
      if (i != N) printf(" ");
      else printf("\n");
    }

    return 0;
}

