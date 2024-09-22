#include <bits/stdc++.h>
#include <unordered_set>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, A, B;
bool vis[2000];
unordered_set<int> graph[2001];
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

scanf("%d %d %d %d", &N, &M, &A, &B);

for (int i = 0; i < M; i++) {
    int u, v;
    scanf("%d %d", &u, &v);

    graph[u].emplace(v);
    graph[v].emplace(u);
  }

q.emplace(A);
vis[A] = true;

  while (!q.empty()) {
    const auto top = q.front(); q.pop();
    if (top == B) break;

    for (const auto &v : graph[top]) {
      if (!vis[v]) {
        vis[v] = true;
        q.emplace(v);
      }
    }
  }

  if (vis[B]) {
    printf("GO SHAHIR!");
  } else {
    printf("NO SHAHIR!");
  }

    return 0;
}

