#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// max sum: 100
string T; int N, dp[101], tempdp[101];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> T >> N;

    int targsz = T.size();

    dp[0] = 0;
    for (int i = 1; i <= targsz; i++) dp[i] = INT32_MAX;

    for (int i = 0; i < N; i++) {
        int M; cin >> M;
        for (int j = 0; j <= targsz; j++) tempdp[j] = dp[j];
        for (int j = 0; j < M; j++) {
            string s; cin >> s;
            int msz = s.size();
            for (int k = 0; k <= targsz; k++) {
                if (k + msz > targsz) break;
                if (dp[k] == INT32_MAX && T.substr(k, msz) != s) continue;
                tempdp[k + msz] = min(tempdp[k + msz], dp[k] + 1);
            }
        }
        for (int j = 0; j <= targsz; j++) dp[j] = tempdp[j];
    }

    cout << (dp[targsz] == INT32_MAX ? -1 : dp[targsz]);

    return 0;
}
