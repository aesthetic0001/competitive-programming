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

multiset<int,less<>> pens[200001];
int n,m,q;
int value[200001];
int color[200001];

struct Bound {
  int color;
  int value;
};

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld %lld %lld",&n,&m,&q);
  for(int i=0;i<n;i++){
    int a,b;scanf("%lld %lld",&a,&b);
    pens[a].emplace(b);
    value[i]=a;
    color[i]=b;
  }

  Bound fir_low={.color=0,.value=INT32_MAX};
  Bound fir_high={.color=0,.value=0};
  int prelim_ans=0;

  for(int i=1;i<=m;i++){
    auto it=pens[i].rbegin();
    int highest=*it;
    prelim_ans+=highest;
    if(highest<fir_low.value){
      fir_low.value=highest;
      fir_low.color=i;
    }
    if(pens[i].count()){
        if(highest>fir_high.value) {
          fir_high.value=highest;
          fir_high.color=i;
        }
    } else {
        if(pens[i].size()>=2){
          it++;
          int second_highest = *it;
          if(second_highest>fir_high.value) {
            fir_high.value=second_highest;
            fir_high.color=i;
          }
        }
    }
  }

  int ans = prelim_ans;
  ans+=max(0ll, fir_high.value - fir_low.value);

  printf("%lld\n",ans);

  while(q--){
      int a,b,c;scanf("%lld %lld %lld",&a,&b,&c);
      if (a==2) {
          counter[1][value[b]]--;
          if(counter[1][value[b]]==0){
            pens[1].erase(value[b]);
          }
          counter[1][c]++;
          pens[1].emplace(c);
          value[b]=c;
      }
      printf("%lld\n",*pens[1].rbegin());
  }
  return 0;
}
