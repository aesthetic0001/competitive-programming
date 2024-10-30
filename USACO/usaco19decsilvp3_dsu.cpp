#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, parent[100001], sz[100001], isG[100001];
bool G[100001];

void mk(int x) {
  parent[x] = x;
  sz[x] = 1;
}

int qu(int x) {
  if (parent[x] == x) {
    return x;
  }
  parent[x] = qu(parent[x]);
  return parent[x];
}

void jn(int x, int y) {
  int pA = qu(x), pB = qu(y);
  if (pA == pB) return;
  if (pB > pA) {
    swap(pA, pB);
  }
  parent[pB] = pA;
  sz[pA] += sz[pB];
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
      char c; scanf(" %c ", &c);
      G[i] = (c == 'G');
      mk(i);
    }

    for (int i = 0; i < N - 1; i++) {
      int x, y; scanf("%d %d", &x, &y);
      if (G[x] == G[y]) jn(x, y);
    }

    for (int i = 0; i < M; i++) {
      int x, y; char c; scanf(" %d %d %c ", &x, &y, &c);
      bool res;
      if (c == 'G') {
        res = G[x] || G[y] || qu(x) != qu(y);
      } else {
        res = !G[x] || !G[y] || qu(x) != qu(y);
      }
      printf("%d", res);
    }

    printf("\n");

    return 0;
}

