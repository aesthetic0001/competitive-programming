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

// weight/edge#, to
vector<PII> graph[100001];
vector<int> ans;
priority_queue<PII, vector<PII>, greater<PII>> pq;
bool vis[100001];

int N, M;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= M; i++) {
      int u, v; scanf("%d %d", &u, &v);

      graph[u].emplace_back(i, v);
      graph[v].emplace_back(i, u);
    }

    pq.emplace(0, 1);

    while (!pq.empty() && ans.size() != N) {
      const auto [weight, top] = pq.top(); pq.pop();

      if (vis[top]) continue;

      vis[top] = true;

      ans.eb(weight);

      for (const auto &[weight, to] : graph[top]) {
        if (!vis[to]) {
          pq.emplace(weight, to);
        }
      }
    }

    if (ans.size() != N) {
        printf("Disconnected Graph");
        return 0;
    }

    for (const auto &v : ans) {
      if (v == 0) continue;
      printf("%d\n", v);
    }

    return 0;
}
