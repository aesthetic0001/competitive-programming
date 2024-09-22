#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, ans = 0;
bool grid[2][200000];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

scanf("%d", &N);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      int res; scanf("%d", &res);
      grid[i][j] = (res == 1);
      if (grid[i][j]) ans += 1;
    }
  }

  ans *= 3;

  // printf("%d\n", ans);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      if (!grid[i][j]) continue;
      if (j != N - 1 && grid[i][j + 1]) {
        ans -= 2;
      }

      if (j % 2 == 0 && ((i == 0 && grid[1][j]) || (i == 1 && grid[0][j]))) {
          ans -= 1;
      }
    }
  }

  printf("%d", ans);

    return 0;
}

