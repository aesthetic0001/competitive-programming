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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;
int n,k,e=0,total=0;
int arr[1000002];
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
scanf("%d %d",&n,&k);
  for(int i=1;i<=n;i++){
    scanf("%1d",&arr[i]);
  }
  int ctr=0;
  for(int i=1;i<=n+1;i++){
    if(arr[i]==1){
      ctr++;
      total++;
    }else if(ctr>0){
      if(ctr%2==0){
        e++;
      }
      ctr=0;
    }
  }
  if(3*e-1==n){
    if(k>0){
      k--;
      total--;
      e--;
    }else{
      printf("-1");
      return 0;
    }
  }
  int ans=2*e+total;
  int evensplit=min(e,k);
  k-=evensplit;total-=evensplit;ans-=3*evensplit;
  // all remaining must be odd
  int oddsplit=min(total,k);
  ans-=oddsplit;
  printf("%d",ans);
  return 0;
}
