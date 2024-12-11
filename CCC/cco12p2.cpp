#include <bits/stdc++.h>

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

// idea: dijkstra but with two distances and we find second fastest.
int N,M,dis1[20001],dis2[20001];
vector<PII>g[20001];
priority_queue<PII,vector<PII>,greater<PII>>pq;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld %lld",&N,&M);
  for(int i=1;i<=N;i++){
    dis1[i]=INT64_MAX;
    dis2[i]=INT64_MAX;
  }
  for(int i=0;i<M;i++){
    int u,v,w;scanf("%lld %lld %lld",&u,&v,&w);
    g[u].eb(mp(w,v));
  }
  pq.emplace(mp(0,1));
  while(!pq.empty()){
    const auto[d,u]=pq.top();pq.pop();
    /*if(d>dis1[u])continue;*/
    for(const auto&[wV,v]:g[u]){
      if(dis1[v]>d+wV){
        dis1[v]=d+wV;
        pq.emplace(mp(dis1[v],v));
      }
      if(d+wV>dis1[v]&&dis2[v]>d+wV){
        dis2[v]=d+wV;
        pq.emplace(mp(dis2[v],v));
      }
    }
  }
  printf("%lld",dis2[N]==INT64_MAX?-1:dis2[N]);
  return 0;
}

