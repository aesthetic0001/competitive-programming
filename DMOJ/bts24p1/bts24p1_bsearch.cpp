#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, K;
set<int, greater<int>> a;
set<int> b;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

scanf("%d %d %d", &N, &M, &K);

  for (int i = 0; i < N; i++) {
    string s; cin >> s;
    a.clear();
    b.clear();
    for (int j = 0; j < M; j++) {
      if (s[j] == 'A') {
        a.emplace(j);
      } else if (s[j] == 'B') {
        b.emplace(j);
      }
    }

    for (int j = 0; j < M; j++) {
      switch (s[j]) {
        case 'A': {
          printf("%c", (b.lower_bound(j) != b.end() && *b.lower_bound(j) - j <= K ? 'N' : 'Y'));
          break;
        }
        case 'B': {
          printf("%c", (a.lower_bound(j) != a.end() && j - *a.lower_bound(j) <= K ? 'N' : 'Y'));
          break;
        }
        default: {
          printf(".");
        }
      }
    }
    printf("\n");
  }

    return 0;
}

