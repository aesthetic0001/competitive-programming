#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define em emplace
#define pb push_back
#define lsb(i) i & -i
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  cin.tie(0);cin.sync_with_stdio(0);
  int n,m;scanf("%d %d",&n,&m);
  if(m>n+1){
    printf("-1");
    return 0;
  }
  int rem=(n+1)-m;
  int mctr=n+1;
  for(int i=1;i<=n;i++){
    int next = i == n ? mctr + 1 : i + 1;
    printf("%d %d\n",next,mctr);
    if(rem>0){
      rem--;
    }else{
      mctr++;
    }
  }
  return 0;
}
