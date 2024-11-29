#include <bits/stdc++.h>
#include <cstdint>
#include <queue>
#include <unordered_map>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>
#define pis pair<int,string>
using namespace std;
int n,m,q;
auto comp=[](pis a,pis b){
  return a.first>b.first;
};
unordered_map<string,vector<pis>>mp;
unordered_map<string, int>dis;
priority_queue<pis,vector<pis>,decltype(comp)>pq(comp);

int qu(string a,string b){
  dis.clear();
  dis[a]=0;
  pq.emplace(make_pair(0,a));
  while(!pq.empty()){
    const auto[d,u]=pq.top();pq.pop();
    if(d>dis[u])continue;
    for(const auto&[w,v]:mp[u]){
      if(dis.find(v)==dis.end()||dis[v]>d+w){
        dis[v]=d+w;
        pq.emplace(make_pair(dis[v],v));
      }
    }
  }
  if(dis.find(b)==dis.end())return INT32_MAX;
  return dis[b];
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    cin>>n>>m;
    for(int i=0;i<m;i++){
      int w;
      string u,v;cin>>u>>v>>w;
      mp[u].emplace_back(make_pair(w,v));
    }
    cin>>q;
    for(int i=0;i<q;i++){
      string origin,dest;cin>>origin>>dest;
      int ans=qu(origin,dest);
      if(ans==INT32_MAX){
        cout<<"Roger\n";
      }else{
        cout<<ans<<'\n';
      }
    }
    return 0;
}

