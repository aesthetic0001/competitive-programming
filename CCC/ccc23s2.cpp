#include <cstring>
#include <iostream>
#define MAX 5000
#define INF 0x3f3f3f3f

int h[MAX];
int dp[MAX][MAX];
int ans[MAX];

using namespace std;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N; cin >> N;

    memset(ans, INF, sizeof(ans));

    ans[0] = 0;

    for (int i = 0; i < N; i++) {
        dp[i][0] = 0;
        cin >> h[i];
    }

    // i is group size - 1
    // j is index of start
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N - i; j++) {
            dp[j][j + i] = abs(h[j] - h[j + i]) + dp[j + 1][j + i - 1];
            ans[i] = min(ans[i], dp[j][j + i]);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << (i == N - 1 ? "" : " ");
    }

    return 0;
}
