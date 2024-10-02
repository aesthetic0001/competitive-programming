#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, edge_ct = 0, needed_edges = 0;
unordered_set<int> graph[1000];
bool visvertex[1000];
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        int temp; scanf("%d", &temp);
        if (temp == 1) {
          edge_ct += 1;
          graph[i].emplace(j);
        };
      }
    }

    for (int i = 0; i < N; i++) {
      if (visvertex[i]) continue;
      int vertices = 1;
      q.emplace(i);
      visvertex[i] = true;
      while (!q.empty()) {
        const int top = q.front(); q.pop();
        for (const auto &v : graph[top]) {
          if (!visvertex[v]) {
            vertices += 1;
            visvertex[v] = true;
            q.emplace(v);
          }
        }
      }
      needed_edges += vertices - 1;
    }

    printf("%d", edge_ct / 2 - needed_edges);

    return 0;
}

