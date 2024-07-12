#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// max sum: 100
string T; int N, dp[101], tempdp[101];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    dp[0] = 0;
    for (int i = 1; i <= 100; i++) dp[i] = INT32_MAX;

    cin >> T >> N;

    int targsz = T.size();

    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        for (int j = 0; j <= 100; j++) tempdp[j] = dp[j];
        for (int j = 0; j < M; j++) {
            string s; cin >> s;
            int msz = s.size();
            for (int k = 0; k <= targsz; k++) {
                if (k + msz > targsz) break;
                if (dp[k] == INT32_MAX) continue;
                if (T.substr(k, k + msz) == s) {
                    tempdp[k + msz] = min(tempdp[k + msz], dp[k] + 1);
                }
            }
        }
        for (int j = 0; j <= 100; j++) dp[j] = tempdp[j];
    }

    cout << (dp[targsz] == INT32_MAX ? -1 : dp[targsz]);

    return 0;
}
