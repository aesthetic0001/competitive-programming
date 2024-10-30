#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, parent[100001], G[100001], H[100001];
int start;
bool isG[100001];
unordered_set<int> graph[100001];

void dfs(int x) {
  G[x] = G[parent[x]];
  H[x] = H[parent[x]];
  if (isG[x]) {
    G[x] += 1;
  } else {
    H[x] += 1;
  }
  for (const auto &adj : graph[x]) {
    if (adj != start && parent[adj] == 0) {
      parent[adj] = x;
      dfs(adj);
    }
  }
}

bool vis[100001];
queue<int> q;

int diameter(int x) {
  int prev = x;
  for (int i = 1; i <= N; i++) {
    vis[i] = false;
  }
  q.emplace(x);
  vis[x] = true;
  while (!q.empty()) {
    const auto top = q.front(); q.pop();
    for (const auto &adj : graph[top]) {
      if (!vis[adj]) {
        vis[adj] = true;
        q.emplace(adj);
      }
    }
  }
  return prev;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
      char c; scanf(" %c ", &c);
      isG[i] = (c == 'G');
    }

    for (int i = 0; i < N - 1; i++) {
      int a, b; scanf("%d %d", &a, &b);
      graph[a].emplace(b);
      graph[b].emplace(a);
    }

    int dia1 = diameter(1);
    start = diameter(dia1);
    dfs(start);

    for (int i = 0 ; i < M; i ++) {
      int a, b; char c; scanf("%d %d %c ", &a, &b, &c);
      bool res;
      if (c == 'H') {
        res = H[b] - H[parent[a]] >= 1 || H[a] - H[parent[b]] >= 1;
      } else {
        res = G[b] - G[parent[a]] >= 1 || G[a] - G[parent[b]] >= 1;
      }
      printf("%d", res);
    }

    return 0;
}

