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

// check if it's possible to form 0 to n using sum of weights

int weights[5] = {0,1,3,3,5};
int n = 12;
// (length, weights)
bool possible[13][5];

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif

  // i: number of weights considered
  // j: the sum to form
  possible[0][0] = true;
  for(int i=1;i<=4;i++){
    for(int j=0;j<=12;j++){
      // build off a previous possibility
      if(j-weights[i]>=0)possible[j][i] |= possible[j-weights[i]][i-1];
      // dont use the current weight
      possible[j][i] |= possible[j][i-1];
    }
  }

  for(int i=0;i<=12;i++){
    bool ans = false;
    for (int j=0;j<=4;j++){
      ans |= possible[i][j];
    }
    printf("%d: %d\n",i,ans);
  }

  return 0;
}

