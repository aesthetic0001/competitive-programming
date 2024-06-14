#include <bits/stdc++.h>
#define int long long

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, M, K, ans[1000001];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N >> M >> K;

    // determine if it is impossible to form first: either exceeds upper bound or too little
    // min N good sample
    if (N > K) {
        cout << -1;
        return 0;
    }

    // M is guaranteed to be less than or equal to N in all cases
    // max is use all to form good sample
    if (K > ((N + (N - M + 1)) * M) / 2) {
        cout << -1;
        return 0;
    }

    K -= N;

    ans[0] = 1;

    cout << ans[0] << " ";

    for (int i = 1; i < N; i++) {
        // there are i elements to the left
        int form = min(min(K, i), M - 1);

        if (form == 0) {
            ans[i] = ans[i - 1];
        } else {
            if (i > form) {
                // cannot form fully, as there are too many elements. need to reuse value
                ans[i] = ans[i - form - 1];
            } else {
                // have enough to form
                ans[i] = ans[i - 1] + 1;
            }
        }

        cout << ans[i];
        if (i != N - 1) cout << " ";

        K -= form;
    }

    return 0;
}
