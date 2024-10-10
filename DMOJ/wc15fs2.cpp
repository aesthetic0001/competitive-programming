#include <bits/stdc++.h>
#include <unordered_map>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, K;
vector<int> spies;
set<int> troughs;
unordered_map<int, int> usedct;

// find first true value
bool bsearch(int time) {
  usedct.clear();
  for (const auto &spy : spies) {
    const auto highest = troughs.upper_bound(spy);
    if (highest == troughs.end())
  }
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) {
      int h; scanf("%d", &h);
      spies.emplace_back(h);
    }

    for (int i = 0; i < M; i++) {
      int t; scanf("%d", &t);
      troughs.emplace(t);
    }

    sort(spies.begin(), spies.end(), greater());

    int l = 1, r = 1000000;

    while (r > l) {
      int mp = l + (r - l) / 2;
      if (bsearch(mp)) {
        l = mp;
      } else {
        r = mp - 1;
      }
    }

    printf("%d", l);

    return 0;
}

