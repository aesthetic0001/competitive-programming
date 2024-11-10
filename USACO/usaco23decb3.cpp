#include <bits/stdc++.h>
#include <cstdint>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int T;

struct Plant {
  int h, rate, order;
};

int divceil(int a, int b) {
  return (a + b - 1) / b;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld", &T);

    for (int i = 0; i < T; i++) {
      int N, lb = 0, ub = INT64_MAX;
      scanf("%lld", &N);
      vector<Plant> a(N);
      for (int j = 0; j < N; j++) {
        scanf("%lld", &a[j].h);
      }
      for (int j = 0; j < N; j++) {
        scanf("%lld", &a[j].rate);
      }
      for (int j = 0; j < N; j++) {
        scanf("%lld", &a[j].order);
      }
      // descending order because relationship should be transitive
      // ie. a > b > c, if b is greater than c after k days and a is greater than b after k days, then it implies that a > c after k days as well.
      sort(a.begin(), a.end(), [&](const auto &a, const auto &b) {
          return a.order > b.order;
      });
      bool broken = false;
      for (int i = 1; i < N; i++) {
        const auto &cur = a[i], prev = a[i - 1];
        if (cur.rate == prev.rate) {
          if (cur.h > prev.h) continue;
          /*printf("broken\n");*/
          broken = true;
          break;
        } else if (cur.rate > prev.rate) {
          // this would only affect the min number of days (lb)
          int days = divceil((prev.h - cur.h + 1), (cur.rate - prev.rate));
          lb = max(lb, days);
        } else if (cur.rate < prev.rate) {
          // need to ensure that the days does not reach this number 
          int days = divceil((cur.h - prev.h), (prev.rate - cur.rate));
          ub = min(ub, days);
        }
      }
      /*printf("%lld %lld\n", ub, lb);*/
      if (broken || lb >= ub) {
        printf("-1\n");
        continue;
      }
      printf("%lld\n", lb);
    }

    return 0;
}

