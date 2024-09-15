#include <bits/stdc++.h>

using namespace std;

int T, N, K;
char ans[100001];

signed main() {
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
          ans[lastG] = 'G';
          a++;
        }
      } else {
          if (abs(lastH - j) > K) {
            lastH = min(N - 1, j + K);
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
