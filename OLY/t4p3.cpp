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

inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline int min(int a,int b){return a<b?a:b;}

using namespace std;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    int n;scanf("%lld",&n);
    vector<int>a,b,c;
    for(int i=0,k;i<n;i++){
        scanf("%lld",&k);
        a.emplace_back(k);
    }
    for(int i=0,k;i<n;i++){
        scanf("%lld",&k);
        b.emplace_back(k);
    }
    for(int i=0,k;i<n;i++){
        scanf("%lld",&k);
        c.emplace_back(k);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    // for(const auto &v:a){
    //     cout<<v<<'\n';
    // }

    int ans=0;
    for (int i = 0; i < n; ++i) {
        int b_val = b[i];
        int count_a = lower_bound(a.begin(), a.end(), b_val) - a.begin();
        int count_c = c.end() - upper_bound(c.begin(), c.end(), b_val);
        ans += 1LL * count_a * count_c;
    }
    printf("%lld",ans);
    return 0;
}
