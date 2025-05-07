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

struct Cow {
  int one;
  int two;
  int three;
};

int n,q;
Cow psa[100001];
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&q);
  for(int i=1,k;i<=n;i++){
    scanf("%d",&k);
    Cow cow;
    Cow &prev=psa[i-1];
    cow.one=prev.one;
    cow.two=prev.two;
    cow.three=prev.three;
    if(k==1){
      cow.one+=1;
    }else if(k==2){
      cow.two+=1;
    }else{
      cow.three+=1;
    }
    psa[i]=cow;
  }
  while(q--){
    int l,r;scanf("%d %d",&l,&r);
    Cow &right=psa[r];
    Cow &left=psa[l-1];
    printf("%d %d %d\n",right.one-left.one,right.two-left.two,right.three-left.three);
  }
  return 0;
}

