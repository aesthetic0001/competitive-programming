#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M;

int parent[200001], sz[200001];

inline void mk(int a) {
  parent[a] = a;
  sz[a] = 1;
}

inline int qu(int a) {
  if (parent[a] == a) {
    return a;
  }
  parent[a] = qu(parent[a]);
  return parent[a];
}

inline bool jn(int a, int b) {
  int pA = qu(a), pB = qu(b);
  if (pA == pB) return false;
  if (sz[pB] > sz[pA]) {
    swap(pA, pB);
  }
  parent[pB] = pA;
  sz[pA] += sz[pB];
  return true;
}

bool flag = false;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
      mk(i);
    }

    for (int i = 0; i < M; i++) {
      int a, b; scanf("%d %d", &a, &b);
      if (!jn(a, b)) {
        if (flag) {
          printf("NO");
          return 0;
        }
        flag = true;
      }
    }

    printf("YES");

    return 0;
}

