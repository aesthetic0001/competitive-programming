#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, K;
vector<int> cows, troughs;

int l = 1, r = 1000001;

bool bsearch(int t) {
  int totalDrank = 0;
  int troughDrank = 0;
  int troughIdx = 0;

  // printf("run %d\n", t);

  while (troughIdx < troughs.size() && totalDrank < cows.size()) {
    if (troughDrank >= t || troughs[troughIdx] < cows[totalDrank] - K || troughs[troughIdx] > cows[totalDrank]) {
      troughDrank = 0;
      troughIdx++;
    } else {
      // printf("put %d in %d\n", cows[totalDrank], troughs[troughIdx]);
      totalDrank += 1;
      troughDrank += 1;
    }
  }

  // printf("filled %d\n", totalDrank);

  // find first true + 1 (ie. first false)
  return totalDrank == cows.size();
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) {
      int p; scanf("%d", &p);
      cows.emplace_back(p);
    }

    for (int i = 0; i < M; i++) {
      int p; scanf("%d", &p);
      troughs.emplace_back(p);
    }

    sort(cows.begin(), cows.end());
    sort(troughs.begin(), troughs.end());

    while (r > l) {
      int mp = (l + r) / 2;
      if (bsearch(mp)) {
        r = mp;
      } else {
        l = mp + 1;
      }
    }

    printf("%d", (l > 1000000 ? -1 : l));

    return 0;
}

