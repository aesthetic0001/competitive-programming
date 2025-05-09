#include <bits/stdc++.h>

#define int long long
#define mp(a,b) make_pair(a,b)
#define eb emplace_back
#define pb push_back
#define lsb(i) i & (-i + 1)
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

int t;vector<int>adj[100000];int dp[100000][2],l[100000],r[100000];

void recurse(int i, int parent) {
    // cout<<"recurse on "<<i<<"\n";
    for(auto &child:adj[i]){
        if(child==parent)continue;
        recurse(child,i);
    }
    for(auto &child:adj[i]){
        if(child==parent)continue;
        dp[i][0]+=max(abs(l[i]-l[child])+dp[child][0], abs(l[i]-r[child])+dp[child][1]);
        dp[i][1]+=max(abs(r[i]-l[child])+dp[child][0], abs(r[i]-r[child])+dp[child][1]);
    }
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    // ios_base::sync_with_stdio(false);cin.tie(0);
    scanf("%lld",&t);
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%lld %lld",&l[i],&r[i]);
            adj[i].clear();
            dp[i][0]=0;
            dp[i][1]=0;
        }
        for(int i=1;i<=n-1;i++){
            int u,v;scanf("%lld %lld",&u,&v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        recurse(1,-1);
        printf("%lld\n",max(dp[1][1],dp[1][0]));
    }
    return 0;
}
