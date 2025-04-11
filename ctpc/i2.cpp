#include <bits/stdc++.h>
#include <cmath>

#define int long long
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
  int a,b;scanf("%lld %lld",&a,&b);
  vector<int>v;
  for(int i=0,k;i<a;i++){
    scanf("%lld",&k);
    v.eb(k);
  }
  sort(v.begin(),v.end());
  int t=0,ans=0;
  for(const auto &val:v){
    t+=powl(val,2);
    ans=val;
    if(t>=b)break;
  }
  if(b>t){
    printf("-1");
    return 0;
  }
  printf("%lld",ans);
  return 0;
}

