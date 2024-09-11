#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    while (true) {
        scanf("%d", &N);
        if (N == 0) break;

        int to[N + 1], ans = 1;
        bool vis[N + 1];

        // can also use dsu but im lazy

        for (int i = 1; i <= N; i++) {
            int a, b; scanf("%d %d", &a, &b);
            to[a] = b;
            vis[i] = false;
        }

        for (int i = 1; i <= N; i++) {
            if (vis[i]) continue;
            int setsz = 1;
            int cur = i;

            while (to[cur] != i) {
                setsz++;
                cur = to[cur];
            }

            ans = lcm(ans, setsz);
        }

        printf("%d\n", ans);
    }

    return 0;
}
