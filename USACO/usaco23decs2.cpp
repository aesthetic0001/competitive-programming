#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N,K;
vector<int> c1(500001),c2(500001),rc2(500001);
int ans=0;
unordered_map<int,int>ct;

int getct(vector<int> &a, vector<int>&b){
  ct.clear();
  for (int i=1;i<=N;i++){
    if(!a[i]||!b[i]){
      continue;
    }
    if(a[i]<=b[i]){
      ct[b[i]-a[i]]+=1;
    }else{
      ct[K-a[i]+b[i]]+=1;
    }
  }
  int best=0;
  for(const auto&[k,v]:ct){
    best=max(best,v);
  }
  return best;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    scanf("%lld %lld",&N,&K);
    for(int i=1;i<=K;i++){
      int a;scanf("%lld",&a);
      c1[a]=i;
    }
    for(int i=1;i<=K;i++){
      int b;scanf("%lld",&b);
      c2[b]=i;
      rc2[b]=K-i+1;
    }
    for(int i=1;i<=N;i++){
      if(!c1[i]&&!c2[i]) {
        ans++;
        continue;
      }
    }
    int best = max(getct(c1,c2),getct(c1,rc2));
    printf("%lld",best+ans);
    return 0;
}

