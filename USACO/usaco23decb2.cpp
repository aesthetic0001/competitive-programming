#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, nights = INT32_MAX, ans = 0;
string bitstr;
bool full = true;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin >> N;
    cin >> bitstr;

    for (int i = 0; i < N; i++) {
      if (bitstr[i] == '0') {
        full = false;
        break;
      }
    }

    if (full) {
      printf("1");
      return 0;
    }

    int start = -1;

    for (int i = 0; i <= N; i++) {
      if (i < N && bitstr[i] == '1') {
        if (start == -1) start = i;
      } else {
        if (start != -1) {
          int curNights = (i - start - 1);
          if (!(start == 0 || i == N)) {
            curNights /= 2;
          }
          nights = min(curNights, nights);
          start = -1;
        }
      }
    }

    for (int i = 0; i <= N; i++) {
      if (i < N && bitstr[i] == '1') {
        if (start == -1) start = i;
      } else {
        if (start != -1) {
          int len = (i - start);
          ans += ceil((double)len / (2.f * (double)nights + 1));
          start = -1;
        }
      }
    }

    printf("%d", ans);
    return 0;
}

