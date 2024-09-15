#include <bits/stdc++.h>

using namespace std;

int T, N, K;
char ans[100001];

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d", &T);

  for (int i = 0; i < T; i++) {
    scanf("%d %d", &N, &K);
    string s;
    cin >> s;

    int a = 0;
    int lastG = INT32_MAX, lastH = INT32_MAX;

    for (int j = 0; j < N; j++) {
      ans[j] = '.';
    }

    for (int j = 0; j < N; j++) {
      if (s[j] == 'G') {
        if (abs(lastG - j) > K) {
          lastG = min(N - 1, j + K);
          if (ans[lastG] != '.') {
              ans[lastG - 1] = ans[lastG];
          }
          ans[lastG] = 'G';
          a++;
        }
      } else {
          if (abs(lastH - j) > K) {
            lastH = min(N - 1, j + K);
            if (ans[lastH] != '.') {
                ans[lastH - 1] = ans[lastH];
            }
            ans[lastH] = 'H';
            a++;
          }
        }
    }

    printf("%d\n", a);

    for (int j = 0; j < N; j++) {
      printf("%c", ans[j]);
    }
    printf("\n");
  }
  return 0;
}
