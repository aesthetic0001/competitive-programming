#include <bits/stdc++.h>
#define MAX 400

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

// interval dp: if [L, R] (inclusive) can be combined
bool dp[MAX + 1][MAX + 1]; int psa[MAX + 1], ans = 0;

inline int sum(int l, int r) {
    return psa[r + 1] - psa[l];
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N; cin >> N;

    psa[0] = 0;

    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        ans = max(ans, k);
        psa[i + 1] += k + psa[i];
        dp[i][i] = true;
    }

    for (int size = 1; size < N; size++) {
        for (int l = 0; size + l < N; l++) {
            int r = l + size;
            int p = l, q = r;

            while (q > p) {
                if (dp[l][p] && dp[q][r] && p + 1 == q && sum(l, p) == sum(q, r)) {
                    dp[l][r] = true;
                    ans = max(ans, sum(l, r));
                } else if (dp[l][p] && dp[q][r] && dp[p + 1][q - 1] && sum(l, p) == sum(q, r)) {
                    dp[l][r] = true;
                    ans = max(ans, sum(l, r));
                }
                if (sum(l, p) < sum(q, r)) {
                    ++p;
                } else {
                    --q;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
