#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int prevA, prevB, N, M, K;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

scanf("%d %d %d", &N, &M, &K);

  for (int i = 0; i < N; i++) {
    prevA = -1, prevB = -1;
    string s; cin >> s;
    char ans[M];

    for (int j = 0; j < M; j++) {
      if (s[j] == 'A') {
        prevA = j;
      } else if (s[j] == 'B') {
        ans[j] = (prevA == -1 || j - prevA > K ? 'Y' : 'N');
      } else {
        ans[j] = '.';
      }
    }

    for (int j = M - 1; j >= 0; j--) {
      if (s[j] == 'B') {
        prevB = j;
      } else if (s[j] == 'A') {
        ans[j] = (prevB == -1 || prevB - j > K ? 'Y' : 'N');
      }
    }
   for (int j = 0; j < M; j++) {
      printf("%c", ans[j]);
    }
    printf("\n");
  }

    return 0;
}

