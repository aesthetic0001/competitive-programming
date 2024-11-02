#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, cows[200000];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < N; i++) {
      scanf("%lld", &cows[i]);
    }

    for (int i = 0; i < M; i++) {
      int k; scanf("%lld", &k);
      int cur = 0;
      for (int j = 0; j < N && cur != k; j++) {
        if (cows[j] > cur) {
          int delta = min(k, cows[j]) - cur;
          cows[j] += delta;
          cur += delta;
        }
      }
    }

    for (int i = 0; i < N; i++) {
      printf("%lld\n", cows[i]);
    }

    return 0;
}

