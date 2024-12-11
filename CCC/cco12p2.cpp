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

#define PII tuple<int, int, int>

using namespace std;

// idea: dijkstra but with two distances and we find second fastest.
int N,M,dis[20001][2];
vector<pair<int,int>>g[20001];
priority_queue<PII,vector<PII>,greater<PII>>pq;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld %lld",&N,&M);
  for(int i=1;i<=N;i++){
    dis[i][0]=INT_MAX;
    dis[i][1]=INT_MAX;
  }
  for(int i=0;i<M;i++){
    int u,v,w;scanf("%lld %lld %lld",&u,&v,&w);
    g[u].eb(mp(w,v));
  }
  pq.emplace(forward_as_tuple(0,1,0));
  while(!pq.empty()){
    const auto[d,u,flag]=pq.top();pq.pop();
    /*if(d>dis[u])continue;*/
    for(const auto&[wV,v]:g[u]){
      if(dis[v][flag]>d+wV){
        dis[v][flag]=d+wV;
        pq.emplace(forward_as_tuple(d+wV,v,flag));
      }else if (d+wV!=dis[v][flag]){
        if(!flag){
           if(dis[v][1]>d+wV){
            dis[v][1]=d+wV;
            pq.emplace(forward_as_tuple(d+wV,v,1));
          }
        }
      }
    }
  }
  printf("%lld",dis[N][1]==INT_MAX?-1:dis[N][1]);
  return 0;
}
