#include <bits/stdc++.h>

#define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define em emplace
#define pb push_back
#define lsb(i) i & -i
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

const int mod = 1e9+7;
int dp[100001][2];
vector<int> g[100001];

void dfs(int node, int parent){
  dp[node][1]=dp[node][0]=1;
  for(auto&v:g[node]){
    if(v==parent)continue;
    dfs(v,node);
    dp[node][0]*=(dp[v][0]+dp[v][1])%mod;
    dp[node][0]%=mod;
    dp[node][1]*=(dp[v][0])%mod;
    dp[node][1]%=mod;
  }
}

signed main() {
  #ifdef LOCAL
  freopen("sample.in","r",stdin);
  #endif
  cin.tie(0);cin.sync_with_stdio(0);
  int n;cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    g[a].eb(b);
    g[b].eb(a);
  }
  dfs(1,0);
  cout<<(dp[1][0]+dp[1][1])%mod;
  return 0;
}

