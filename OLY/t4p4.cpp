#include <bits/stdc++.h>
#include <cassert>

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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

inline int mpow(int base, int exp, int mod){
    int ans = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = (ans * base) % mod;
        }
        base = (base * base) % mod;
        exp/=2;
    }
    return ans;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    // model like decision tree, for every edge we can either continue off of node a or node b, depending on which one maximizes the final value
    // we will just construct the maximum tree. we should always be able to represent the final state this way
    int n,m;scanf("%lld %lld",&n,&m);vector<int>a;vector<vector<int>>g(n, vector<int>(n-1));
    for(int i=0,k;i<n;i++){
        scanf("%lld",&k);
        a.emplace_back(k);
    }
    // at most 500 c 2 ~ 140k
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int pij=mpow(a[i],a[j],m);
            int pji=mpow(a[j],a[i],m);
            g[i][j]=g[j][i]=(pij+pji) % m;
        }
    }
    vector<bool>vis(n,false);
    vector<int>best(n,INT64_MIN);
    best[0]=0;
    int ans=0;
    for(int _=0;_<n;_++){
        int u=-1;
        for(int i=0;i<n;i++){
            if (!vis[i]&&(u==-1||best[i]>best[u])) {
                u=i;
            }
        }
        assert(u!=-1);
        vis[u]=true;
        ans+=best[u];
        for(int v=0;v<n;v++){
            if (!vis[v]) {
                best[v]=max(best[v],g[u][v]);
            }
        }
    }
    printf("%lld", ans);
    return 0;
}
