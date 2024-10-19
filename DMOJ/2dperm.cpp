#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int diff[25000001];
int grid[5001][5001];
int N, M, Q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d %d", &N, &M, &Q);

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        /*printf("from %d to %d\n", i * j, N * M - (N - i + 1) * (M - j + 1));*/
        diff[i * j] += 1;
        diff[N * M - (N - i + 1) * (M - j + 1) + 2] -= 1;
      }
    }

    for (int i = 1; i <= N * M; i++) {
      diff[i] += diff[i - 1];
    }

    for (int i = 0; i < Q; i++) {
      int k; scanf("%d", &k);
      printf("%d\n", diff[k]);
    }

    return 0;
}

