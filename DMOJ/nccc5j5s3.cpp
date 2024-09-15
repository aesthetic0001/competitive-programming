#include <bits/stdc++.h>
#include <queue>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M;

unordered_set<int> graph[51];
queue<int> q;
vector<PII> vertices;
bool vis[51];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
    int a, b; scanf("%d %d", &a, &b);
    graph[a].emplace(b);
    vertices.emplace_back(make_pair(a, b));
  }

  for (const auto &[a, b] : vertices) {
    for (int i = 0; i <= 50; i++) {
      vis[i] = false;
    }

    graph[a].erase(b);

    q.emplace(1);
    vis[1] = true;

    while (!q.empty()) {
      const int top = q.front(); q.pop();

      for (const auto &adj : graph[top]) {
        if (!vis[adj]) {
          vis[adj] = true;
          q.emplace(adj);
        }
      }
    }

    if (vis[N]) printf("YES\n");
    else printf("NO\n");
    graph[a].emplace(b);
  }

    return 0;
}

