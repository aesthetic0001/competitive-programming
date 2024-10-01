#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int P, Y, T, l = 1, r;

// find the first false value
bool bs(int a) {
  int principal = 0;
  for (int i = 0; i < Y; i++) {
    principal += a;
    principal *= P;
    principal /= 100;
    if (principal >= T) {
      return false;
    }
  }
  return principal < T;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld %lld %lld", &P, &Y, &T);

    P += 100;
    r = T;

    while (r > l) {
      int mp = (l + r) / 2;

      if (bs(mp)) {
        l = mp + 1;
      } else {
        r = mp;
      }
    }

    printf("%lld", l);

    return 0;
}

