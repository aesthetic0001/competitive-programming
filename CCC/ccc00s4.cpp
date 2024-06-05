#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int dp[5281], clubs[32];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, C; cin >> N >> C;

    dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        dp[i] = 5281;
    }


    for (int i = 0; i < C; i++) cin >> clubs[i];

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[j] != 5281) {
                // try branching out of this explored node
                int ctr = 1;
                while (ctr * clubs[i] + j <= N) {
                    dp[ctr * clubs[i] + j] = min(ctr + dp[j], dp[ctr * clubs[i] + j]);
                    ++ctr;
                }
            }
        }
    }

    if (dp[N] == 5281) cout << "Roberta acknowledges defeat.";
    else cout << "Roberta wins in " << dp[N] << " strokes.";

    return 0;
}
