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

int a,b,c,d;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d %d %d",&a,&b,&c,&d);
  int prelim=2*(a+b+c+d);
  int ans=INT32_MAX;
  ans=min(ans,prelim-2*(min(a,c)));
  ans=min(ans,prelim-2*(min(b,d)));
  printf("%d",ans);
  return 0;
}

