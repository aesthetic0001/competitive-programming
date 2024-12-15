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

int n,m,t;
// vector<PII>adj[301];
int dis[301][301];

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d %d %d",&n,&m,&t);
  for(int i=1;i<=n;i++){
    for(int j=0;j<=n;j++){
      dis[i][j]=INT32_MAX;
    }
  }
  while(m--){
    int u,v,w;scanf("%d %d %d",&u,&v,&w);
    dis[u][v]=w;
  }
  for(int k=1;k<=n;k++){
    for(int u=1;u<=n;u++){
      for(int v=1;v<=n;v++){
        if(dis[u][k]<INT32_MAX&&dis[k][v]<INT32_MAX){
          dis[u][v]=min(dis[u][v],max(dis[u][k],dis[k][v]));
        }
      }
    }
  }
  while(t--){
    int u,v;scanf("%d %d",&u,&v);
    if(dis[u][v]==INT32_MAX)printf("-1\n");
    else printf("%d\n",dis[u][v]);
  }
  return 0;
}

