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
// #define ll long long

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}
const int MAX=2e5+5;
using namespace std;
int n,m,q;
int running_sum=0;
int color[MAX],prettiness[MAX];
multiset<int> colors[MAX],sec_mx,mx;

void remove(int c) {
    int color_max = *colors[c].rbegin();
    mx.extract(color_max); running_sum -= color_max;
    if(colors[c].size() > 1) sec_mx.extract(*next(colors[c].rbegin()));
}

void add(int c) {
    int color_max = *colors[c].rbegin();
    mx.insert(color_max); running_sum += color_max;
    if(colors[c].size() > 1) sec_mx.emplace(*next(colors[c].rbegin()));
}

int comp() {
    int low_max=*mx.begin();
    auto high_max=sec_mx.rbegin();
    if(sec_mx.empty() || low_max>=*high_max){
        return running_sum;
    }
    return running_sum + *high_max - low_max;
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld %lld %lld",&n,&m,&q);
  for(int i=1;i<=n;i++){
    int c,p;scanf("%lld %lld",&c,&p);
    color[i]=c;prettiness[i]=p;
    colors[c].emplace(p);
  }
  for(int c=1;c<=m;c++){
      add(c);
  }
  printf("%lld\n",comp());
  while(q--){
      int qt,i,v;scanf("%lld %lld %lld",&qt,&i,&v);
      if(qt == 1){
          remove(color[i]); remove(v);
          colors[color[i]].extract(prettiness[i]);
          colors[v].emplace(prettiness[i]);
          add(color[i]); add(v);
          color[i]=v;
      }else{
          remove(color[i]);
          colors[color[i]].extract(prettiness[i]);
          colors[color[i]].emplace(v);
          add(color[i]);
          prettiness[i]=v;
      }
      printf("%lld\n",comp());
  }
  return 0;
}
