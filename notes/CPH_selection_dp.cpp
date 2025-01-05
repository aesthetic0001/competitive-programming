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

int products[3][8]={{6,9,5,2,8,9,1,6},{8,2,6,2,7,5,7,2},{5,3,9,7,3,5,1,4}};
// subset, days
// sort of like the other DP examples in CPH
int dp[1<<3][9];
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif

  for(int i=0;i<(1<<3);i++){
    for(int j=0;j<=8;j++){
      dp[i][j]=INT32_MAX;
    }
  }

  dp[0][0]=0;

  /*for(int i=0;i<=(1<<3)-1;i++){*/
  /*  for(int j=0;j<8;j++){*/
  /*    printf("%d %d %d\n",i,j,dp[i][j]);*/
  /*  }*/
  /*}*/

  for(int i=0;i<3;i++){
    /*printf("%d %d\n",i,products[i][0]);*/
    dp[(1<<i)][0]=products[i][0];
  }


  for(int i=1;i<=8;i++){
    for(int subset=0;subset<(1<<3);subset++){
      // dont use the value from current subset, use prev. subset
      dp[subset][i]=dp[subset][i-1];
      /*printf("%d %d: extended %d to %d\n",i,subset,dp[subset][i],dp[subset][i-1]);*/
      for(int product=0;product<3;product++){
        if(subset&(1<<product)){
          /*printf("accounting for product %d\n",product);*/
          if(dp[subset^(1<<product)][i-1]!=INT32_MAX){
            dp[subset][i]=min(dp[subset][i],dp[subset^(1<<product)][i-1]+products[product][i-1]);
          }
        }
      }
    }
  }

  printf("%d\n",dp[(1<<2) + (1<<1) + (1<<0)][8]);
  /*printf("%d\n",dp[(1<<1)][2]);*/

  return 0;
}

