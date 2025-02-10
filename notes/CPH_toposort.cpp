#include <algorithm>
#include <bits/stdc++.h>

// #define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#define clr(array,fill) memset(array,fill,sizeof(array))
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

// 0 = notvis, 1 = vis, didn't terminate, 2 = vis and terminated
int state[7];
vector<int> adj[7]={{},{2},{3},{6},{1,5},{2,3},{}};
vector<int> topo;

void dfs(int node){
  state[node]=1;
  for(const auto &v:adj[node]){
    if(state[v]==1){
      printf("Cycle detected!");
      return;
    }
    if(state[v]==2){
      continue;
    }
    dfs(v);
  }
  state[node]=2;
  topo.eb(node);
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  for(int i=1;i<=6;i++){
    if(state[i]!=0){
      continue;
    }
    dfs(i);
  }
  reverse(topo.begin(), topo.end());
  for(const auto &v:topo){
    printf("%d ",v);
  }
  return 0;
}

