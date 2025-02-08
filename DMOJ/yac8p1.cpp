#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clr(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

int n,arr[1000001],ans=0;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  // the largest value determines where the sort rb will end up. hence, if the rb is greater than the current value, then it indicates that the sort does not need to proceed
  int MAX=0;
  for(int i=1;i<=n;i++){
    MAX=max(MAX,arr[i]);
    // if its neq, then even if it's larger it needs to be swapped
    if(MAX>arr[i]||arr[i]!=i){
      ans++;
    }
  }
  printf("%d",ans);
  return 0;
}

