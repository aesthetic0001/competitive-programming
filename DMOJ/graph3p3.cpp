#include <bits/stdc++.h>
#include <tuple>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

struct comp {
  public:
  bool operator()(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<2>(a) != get<2>(b)) {
      // only one of them must be 1
      return get<2>(a);
    }
    // otherwise, determine by the weight
    return get<1>(b) < get<1>(a);
  }
};

int N, M;
// target, weight, dangerous
bool vis[101];
vector<tuple<int, int, int>> graph[101];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> pq;
int dang = 0, cost = 0;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
      int a, b, c, d;
      scanf("%d %d %d %d", &a, &b, &c, &d);
      graph[a].emplace_back(forward_as_tuple(b, c, d));
      graph[b].emplace_back(forward_as_tuple(a, c, d));
    }

    pq.emplace(forward_as_tuple(1, 0, 0));

    while (!pq.empty()) {
      const auto [b, c, d] = pq.top(); pq.pop();
      if (vis[b]) {
        continue;
      }

      vis[b] = true;

      if (d == 1) {
        dang += 1;
      }

      cost += c;

      for (const auto &adj : graph[b]) {
        if (vis[get<0>(adj)]) continue;
        pq.emplace(adj);
      }
    }

    printf("%d %d", dang, cost);

    return 0;
}

