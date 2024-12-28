#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clear(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int grid[5][5] = {
        {3, 7, 9, 2, 7},
        {9, 8, 3, 5, 5},
        {1, 7, 9, 8, 5},
        {3, 8, 6, 4, 10},
        {6, 3, 9, 7, 8}
};

// padded
int best[6][6];

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  for (int i=1;i<=5;i++){
    for (int j=1;j<=5;j++){
      best[i][j]=max(best[i][j-1],best[i-1][j])+grid[i-1][j-1];
    }
  }
  printf("Best at bottom right: %d\n",best[5][5]);
  return 0;
}

