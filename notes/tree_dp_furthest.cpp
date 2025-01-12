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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;
#define N 10
// assume nodes labelled 1 to N
vector<int> adj[N];
int n;
bool vis[N];
int ans[N]; 

int dfs(int u,int depth=0){
  printf("vis %d\n",u);
  int max1=0;
  int max2=0;
  vis[u]=true;
  for(int v:adj[u]){
    if(vis[v])continue;
    int res=dfs(v,depth+1);
    printf("res of %d: %d\n",v,res);
    if(res>max1){
      printf("max1: %d => %d\n",max1,res);
      max2=max1;
      max1=res;
    }else{
      printf("max2: %d => %d\n",max2,res);
      max2=max(max2,res);
    }
  }
  ans[u]=depth+max1 + max2;
  return 
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  scanf("%d",&n);
  while(n--){
    int a,b;scanf("%d %d",&a,&b);
    adj[a].eb(b);
    adj[b].eb(a);
  }
  // root arbritrarily at 1
  dfs(1);
  printf("%d",ans[1]);
  return 0;
}

