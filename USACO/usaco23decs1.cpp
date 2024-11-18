#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, K, ans = 0;
// (weight, count)
vector<PII>C;
auto cmp = [](PII a,PII b) {
  return a.first<b.first;
};
// (parent, count)
set<PII,decltype(cmp)>s(cmp);
signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    scanf("%lld %lld %lld\n",&N,&M,&K);
    for(int i=0;i<N;i++){
      int w,c;scanf("%lld %lld",&w,&c);
      C.emplace_back(make_pair(w,c));
    }
    sort(C.begin(),C.end(),greater<PII>());
    for(const auto&[w,c]:C){
      /*printf("start %lld\n",c);*/
      int available=c;
      while(available){
        auto cto=s.rbegin();
        if(cto==s.rend()) break;
        auto parent=*cto;
        if(parent.first<w+K)break;
        s.erase(parent);
        if(available<parent.second){
          /*printf("partial stack %lld:%lld\n",parent.first,c);*/
          s.emplace(make_pair(parent.first,parent.second-available));
          available=0;
        }else{
          /*printf("overwrite stack %lld:%lld\n",parent.first,parent.second);*/
          available-=parent.second;
        }
      }
      int maxadditional=min(M,available);
      int tot=(c-available) + maxadditional;
      M-=maxadditional;
      ans+=tot;
      if(tot>0){
        /*printf("total towers %lld:%lld\n",w,(c - available) + maxadditional);*/
        s.emplace(make_pair(w,tot));
      }
    }

    printf("%lld",ans);

    return 0;
}
