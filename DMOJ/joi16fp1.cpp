#include <bits/stdc++.h>

#define int long long
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
int alt[200001],dif[200002];
int n,q,s,t,temp=0;

int f(int delta){
  if(delta>0){
    return -delta*s;
  }
  return -delta*t;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
scanf("%lld %lld %lld %lld",&n,&q,&s,&t);
  scanf("%lld",&alt[0]);
  for(int i=1;i<=n;i++){
    scanf("%lld",&alt[i]);
    dif[i]=alt[i]-alt[i-1];
    temp+=f(dif[i]);
  }
  for(int i=0,l,r,x;i<q;i++){
    scanf("%lld %lld %lld",&l,&r,&x);
    temp-=f(dif[l])+f(dif[r+1]);
    dif[l]+=x;
    if(r+1<=n)dif[r+1]-=x;
    temp+=f(dif[l])+f(dif[r+1]);
    printf("%lld\n",temp);
  }
  return 0;
}

