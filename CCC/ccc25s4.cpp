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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

using s = tuple<int,int,int>;
using PII = pair<int,int>;

vector<PII> g1[200000];
int val[200001],dist[200001];
priority_queue<s,vector<s>,greater<>> pq;

signed main() {
    int n,m;scanf("%lld %lld",&n,&m);
    assert(n>1);
    for (int i=0;i<m;i++){
        int u, v, w; scanf("%lld %lld %lld",&u,&v,&w);
        dist[i]=INT64_MAX;
        g1[u].eb(mp(v, i));
        g1[v].eb(mp(u, i));
        val[i]=w;
    }
    pq.push({0, 1, m});
    while(!pq.empty()){
        const auto [cost,node,edge]=pq.top();pq.pop();
        if (cost>dist[edge]){
            continue;
        }
        if(node==n){
            printf("%lld",cost);
            return 0;
        }
        for(const auto &[other,otheredge]:g1[node]){
            int transition = abs(val[otheredge]-val[edge]);
            if(dist[otheredge]>cost+transition){
                dist[otheredge]=cost+transition;
                pq.push({dist[otheredge],other,otheredge});
            }
        }
    }
    return 0;
}