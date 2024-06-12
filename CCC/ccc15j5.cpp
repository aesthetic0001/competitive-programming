#include <bits/stdc++.h>
#define int long long

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, K;
int dp[251][251][251];

inline int DP(int n, int k, int max, int total = 0) {
    if (n == k || k == 1) {
        return 1;
    }

    int rightmostPies = min(max, n - (k - 1));

    if (dp[n][k][rightmostPies]) return dp[n][k][rightmostPies];

    while (true) {
        if (n - rightmostPies < k - 1 || ((n - rightmostPies) > rightmostPies * (k - 1))) {
            dp[n][k][min(max, n - (k - 1))] = total;
            return total;
        }
        total += DP(n - rightmostPies, k - 1, rightmostPies);
        --rightmostPies;
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> N >> K;
    cout << DP(N, K, INT64_MAX) << "\n";
    return 0;
}
