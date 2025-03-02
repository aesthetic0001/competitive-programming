#include <bits/stdc++.h>
#include <cassert>
#include <tuple>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define em emplace
#define pb push_back
#define lsb(i) i & -i
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>
#define TII tuple<int,int,int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

// cost, cur_l, node
priority_queue<TII,vector<TII>,greater<>> pq;
queue<TII>q;
vector<PII> adj[200001];
int dis[200001][101];
int dis2[200001];
int n,m;

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d",&n,&m);
  bool gt_10 = false;
  for(int i=0;i<=200000;i++){
      dis2[i]=0;
    for(int j=0;j<=100;j++){
      dis[i][j]=INT32_MAX;
    }
  }
  for(int i=0;i<m;i++){
    int u,v,w;scanf("%d %d %d",&u,&v,&w);
    adj[u].eb(mp(v,w));
    adj[v].eb(mp(u,w));
    if(w>10){
      gt_10=true;
    }
  }
  if(gt_10) {
      // only one path, must traverse through it normally
      int ans = 0;
      while
      printf("%d",ans);
  } else {
      dis[1][0]=0;
      pq.emplace(forward_as_tuple(0,0,1));
      while(!pq.empty()){
        const auto [cost,cur_l,node]=pq.top();pq.pop();
        if(cost>dis[node][cur_l]){
          continue;
        }
        for(const auto &[v,w]:adj[node]){
          if(dis[v][w]>cost+abs(w-cur_l)) {
            dis[v][w]=cost+abs(w-cur_l);
            /*printf("vis %d from %d: %d\n",v,node,dis[v]);*/
            pq.emplace(forward_as_tuple(dis[v][w],w,v));
          }
        }
      }
      int ans=INT32_MAX;
      for(int i=0;i<=100;i++){
        ans=min(dis[n][i],ans);
      }
      printf("%d",ans);
  }
  return 0;
}
