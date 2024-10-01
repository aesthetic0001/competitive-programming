#include <bits/stdc++.h>
#include <unordered_set>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

unordered_set<int> graph[200001];
vector<PII> ans;
int N;

void skibidi(int node, int parent, bool flag = false) {
  for (const auto &v : graph[node]) {
    if (v == parent) continue;
    if (flag) {
      ans.emplace_back(make_pair(parent, v));
    }
    skibidi(v, node, !flag);
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

    printf("%d\n", graph[1].size() + 1);

    ans.clear();
    skibidi(1, 1);
    printf("%d\n", ans.size() + 1);
    for (const auto &[u, v] : ans) {
      printf("%d %d\n", u, v);
    }

    for (const auto &adj : graph[1]) {
      ans.clear();
      skibidi(adj, 1);
      printf("%d\n", ans.size() + 1);
      for (const auto &[u, v] : ans) {
        printf("%d %d\n", u, v);
      }
    }


    return 0;
}

