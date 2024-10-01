#include <bits/stdc++.h>
#include <unordered_set>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

unordered_set<int> graph[200001];
vector<PII> ans[200001];
bool vis[200001];
int N;

void skibidi(int root, int node, int grandparent, bool flag = true) {
  // printf("vis %d p %d\n", node, grandparent);
  if (flag && root != node) {
    ans[root].emplace_back(make_pair(node, grandparent));
  }
  vis[node] = true;
  for (const auto &v : graph[node]) {
    if (vis[v]) continue;
    skibidi(root, v, (flag ? node : grandparent), !flag);
  }
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 0; i < N - 1; i ++) {
      int u, v; scanf("%d %d", &u, &v);
      graph[u].emplace(v);
      graph[v].emplace(u);
    }

    int k = graph[1].size() + 1;

    printf("%d\n", k);

    skibidi(1, 1, 1);

    printf("%d\n", ans[1].size() + 1);

    for (const auto &[u, v] : ans[1]) {
      printf("%d %d\n", u, v);
    }

    for (const auto &adj : graph[1]) {
      for (int i = 0; i <= 200000; i++) {
        vis[i] = false;
      }
      skibidi(adj, adj, adj);
      printf("%d\n", ans[adj].size() + 1);
      for (const auto &[u, v] : ans[adj]) {
        printf("%d %d\n", u, v);
      }
    }


    return 0;
}

