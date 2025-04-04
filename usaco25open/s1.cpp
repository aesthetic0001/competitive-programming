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

    int t;scanf("%lld",&t);
    while(t--){
        int m,k;scanf("%lld %lld",&m,&k);
        vector<int>ans;
        int cur = m;
        // M is at most 10^9, so this is at most 2^29 (29 bits flipped)
        // this means the highest XOR should be 2^5 - 1 or 31 (16 flipped, 8 flipped, 4 flipped, ..., 1 flipped), so no need to check K
        for (int i=0;i<=4;i++){
            if(k & (1 << i)) {
                // this bit is needed
                int v = (1 << (1 << i)) - 1;
                // XOR of popcount, we need 2^i bits to be set, so we need 2^(2 ^ i) - 1
                cur -= v;
                ans.eb(v);
            }
        }
        if (cur < 0) {
            printf("-1\n");
            continue;
        }
        if(cur>=2){
            if (cur % 2 == 0) {
                ans.eb(cur / 2);
                ans.eb(cur / 2);
            } else {
                ans.eb(1);
                ans.eb(2);
                cur -= 3;
                if (cur > 0) {
                    ans.eb(cur / 2);
                    ans.eb(cur / 2);
                }
            }
        }else if (cur != 0){
            // must be 1
            if (ans[0] == 1) {
                ans[0] = 2;
            } else {
                printf("-1\n");
                continue;
            }
        }
        printf("%lld\n",ans.size());
        for (const auto &v : ans) {
            printf("%lld ",v);
        }
        printf("\n");
    }

    return 0;
}
