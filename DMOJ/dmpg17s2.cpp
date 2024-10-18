#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int p[100001], sz[100001];

void mk(int i) {
  p[i] = i;
  sz[i] = 0;
}

int qu(int i) {
  if (p[i] == i) return i;
  p[i] = qu(p[i]);
  return p[i];
}

void jn(int a, int b) {
  int pA = qu(a), pB = qu(b);

  if (pA == pB) return;

  if (sz[pB] > sz[pA]) {
    swap(pA, pB);
  }

  p[pB] = pA;
  sz[pA] += sz[pB];
}

int N, Q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &Q);

    for (int i = 1; i <= N; i++) {
      mk(i);
    }

    for (int i = 0; i < Q; i++) {
      char c; int x, y;
      scanf(" %c %d %d", &c, &x, &y);

      /*printf("%c %d %d\n", c, x, y);*/

      if (c == 'A') {
        jn(x, y);
      } else {
        int pA = qu(x), pB = qu(y);
        if (pA == pB) {
          printf("Y\n");
        } else {
          printf("N\n");
        }
      }
    }

    return 0;
}

