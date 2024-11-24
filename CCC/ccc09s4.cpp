#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;
int N,T,K,D,ans=INT32_MAX,P[5001],dist[5001];
vector<PII>g[5001];
priority_queue<PII,vector<PII>,greater<PII>>pq;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
  for(int i=0;i<=5000;i++){
    P[i]=INT32_MAX;
    dist[i]=INT32_MAX;
  }
  scanf("%d",&N);
  scanf("%d",&T); 
  for(int i=0;i<T;i++){
    int u,v,w;scanf("%d %d %d",&u,&v,&w);
    g[u].emplace_back(make_pair(w,v));
    g[v].emplace_back(make_pair(w,u));
  }
  scanf("%d",&K);
  for(int i=0;i<K;i++){
    int u,c;scanf("%d %d",&u,&c);
    P[u]=c;
  }
  scanf("%d",&D);
  dist[D]=0;
  pq.emplace(make_pair(0,D));
  while(!pq.empty()){
    const auto[d,u]=pq.top();pq.pop();
    if(d>dist[u])continue;
    if(P[u]!=INT32_MAX)ans=min(d+P[u],ans);
    for(const auto [w,v]:g[u]){
      if(dist[v]>d+w){
        dist[v]=d+w;
        pq.emplace(make_pair(dist[v],v));
      }
    }
  }
  printf("%d",ans);
  return 0;
}
