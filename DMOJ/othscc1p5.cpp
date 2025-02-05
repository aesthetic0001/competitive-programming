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
int n,m,k;
// [dis][collected]
int dis[20001][31];
int self_build[31], item_ct[31];
// [item][node], checks if the ith item exists at this node
bool buildings[20001][31];

// (other, weight)
vector<PII> adj[20001];

// (dist, node, items collected)
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%lld %lld %lld",&n,&m,&k);
  for(int i=1;i<=k;i++){
    scanf("%lld",&self_build[i]);
  }
  for(int i=1;i<=k;i++){
    scanf("%lld",&item_ct[i]);
  }
  for(int i=1;i<=k;i++){
    while(item_ct[i]--){
      int v;scanf("%lld",&v);
      buildings[v][i]=true;
    }
  }
  for(int i=0;i<m;i++){
    int a,b,c;scanf("%lld %lld %lld",&a,&b,&c);
    adj[b].eb(mp(a,c));
    adj[a].eb(mp(b,c));
  }
  for(int i=1;i<=n;i++){
    adj[i].eb(mp(i,0));
  }
  for(int i=0;i<=20000;i++){
    for(int t=0;t<=30;t++){
      dis[i][t]=INT32_MAX;
    }
  }
  pq.emplace(forward_as_tuple(0,1,0));
  dis[1][0]=0;
  while(!pq.empty()){
    const auto[dist,node,collected]=pq.top();pq.pop();
    /*printf("%lld %lld %lld\n",dist,node,collected);*/
    if(collected==k){
      printf("%lld",dist);
      return 0;
    }
    if(dist>dis[node][collected]){
      continue;
    }
    for(const auto &[adjacent,w]:adj[node]){
    if(buildings[adjacent][collected+1] && dis[adjacent][collected+1]>dist+w){
        dis[adjacent][collected+1]=dist+w;
        pq.emplace(forward_as_tuple(dist+w,adjacent,collected+1));
    }else if(dis[adjacent][collected] > dist+w){
      // you wouldn't want to visit it without taking it anyways if you are able to take it already (why would you skip over an item on the path at no additional cost?)
        dis[adjacent][collected]=dist+w;
        pq.emplace(forward_as_tuple(dist+w,adjacent,collected));
      }
    }
    if(dis[node][collected+1]>dist+self_build[collected+1]){
      dis[node][collected+1]=dist+self_build[collected+1];
      pq.emplace(forward_as_tuple(dist+self_build[collected+1],node,collected+1));
    }
  }

  return 0;
}
