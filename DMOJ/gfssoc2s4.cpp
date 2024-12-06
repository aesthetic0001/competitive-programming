#include <bits/stdc++.h>
#include <tuple>

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

using namespace std;
int N,M,D;
vector<tuple<int,int,int>> adj[500001];
// 2nd flag: cindy
int dis[500001][2];
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
void dij(int source){
  pq.emplace(forward_as_tuple(0,source,false));
  for(int i=0;i<=N;i++){
    dis[i][0]=INT32_MAX;
    dis[i][1]=INT32_MAX;
  }
  dis[1][0]=0;
  dis[1][1]=0;
  while(!pq.empty()){
    const auto[d,u,cindy]=pq.top();pq.pop();
    if(d>dis[u][cindy]){
      continue;
    }
    for(const auto&[w,v,flag]:adj[u]){
      if(flag&&cindy){
        continue;
      }
      if(dis[v][cindy]>d+w) {
        dis[v][cindy]=d+w;
        pq.emplace(forward_as_tuple(d+w,v,cindy||flag));
      }
    }
  }
}
signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld %lld",&N,&M);
  for(int i=0;i<M;i++){
    int u,v,w;scanf("%lld %lld %lld",&u,&v,&w);
    adj[u].emplace_back(forward_as_tuple(w,v,0));
  }
  scanf("%lld",&D);
  for(int i=0;i<D;i++){
    int u,v,w;scanf("%lld %lld %lld",&u,&v,&w);
    adj[u].emplace_back(forward_as_tuple(w,v,1));
  }
  dij(1);
  int ans = min(dis[N][0],dis[N][1]);
  if(ans==INT32_MAX){
    printf("-1");
    return 0;
  }
  printf("%lld",min(dis[N][0],dis[N][1]));
  return 0;
}
