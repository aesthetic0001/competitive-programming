#include <bits/stdc++.h>

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
const int mx=2e5;
int n,a[mx],c[mx],deps[mx],ans=0;
bool selfOK[mx],depOK[mx];
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld",&n);
  for(int i=1;i<=n;i++){
    scanf("%lld",&a[i]);
  }
  for(int i=1;i<=n;i++){
    scanf("%lld",&c[i]);
  }
  for(int i=1;i<=n;i++){
    deps[a[i]]+=c[a[i]];
    depOK[i]=a[a[i]]==a[i];
    selfOK[i]=a[i]==i;
  }
  for(int i=1;i<=n;i++){
    if(depOK[i]||selfOK[a[i]])continue;
    if(c[i]>=c[a[i]]){
      ans+=c[a[i]];
      depOK[a[i]]=true;
      selfOK[a[i]]=true;
      a[a[i]]=a[i];
    }else{
      ans+=c[i];
      depOK[i]=true;
      selfOK[i]=true;
      a[i]=i;
    }
  }
  printf("%lld",ans);
  return 0;
}

