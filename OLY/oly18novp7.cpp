#include <bits/stdc++.h>

using namespace std;

int X, Y;

int dp[100001];

queue<int> q;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    for (int i = 0; i <= 100000; i++) {
        dp[i] = INT32_MAX;
    }

    cin >> X >> Y;

    dp[X] = 0;

    q.emplace(X);

    int visct = 0;

    while (!q.empty()) {
        const int val = q.front(); q.pop();
        const int cur = dp[val];

        visct++;

        if (val + 1 <= 100000 && dp[val + 1] > cur + 1) {
            dp[val + 1] = cur + 1;
            q.emplace(val + 1);
        }

        if (val - 1 >= 0 && dp[val - 1] > cur + 1) {
            dp[val - 1] = cur + 1;
            q.emplace(val - 1);
        }
        if (2 * val <= 100000 && dp[2 * val] > cur + 1) {
            dp[2 * val] = cur + 1;
            q.emplace(2 * val);
        }
    }

    cout << dp[Y];

    return 0;
}
