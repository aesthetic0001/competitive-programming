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
  int a,b,c,d,e,f;scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
  printf("%d",a+5*b+10*c+25*d+100*e+200*f);
  return 0;
}

