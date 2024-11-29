#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clear(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;
int n,m,dis1[100000],dis2[100000],ans=0;
vector<PII>adj[100000];
priority_queue<PII,vector<PII>,greater<PII>>pq;
void dij(int source,int *dis){
  for(int i=0;i<n;i++){
    dis[i]=INT32_MAX;
  }
  pq.emplace(mp(0,source));
  dis[source]=0;
  while(!pq.empty()){
    const auto[d,u]=pq.top();pq.pop();
    if(d>dis[u])continue;
    for(const auto&[w,v]:adj[u]){
      if(dis[v]>d+w){
        dis[v]=d+w;
        pq.emplace(mp(dis[v],v));
      }
    }
  }
}
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    int u,v,w;scanf("%d %d %d",&u,&v,&w);
    adj[u].eb(mp(w,v));
    adj[v].eb(mp(w,u));
  }
  dij(0,dis1);
  dij(n-1,dis2);
  for(int i=0;i<n;i++){
    ans=max(ans,dis1[i]+dis2[i]);
  }
  printf("%d",ans);
  return 0;
}

