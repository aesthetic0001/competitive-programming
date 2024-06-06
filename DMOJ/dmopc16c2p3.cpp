#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M; cin >> N >> M;

        int A = 0, B = 0;

        for (int j = 0; j < M; j++) {
            int x, y; cin >> x >> y;
            A = max(x, A);
            B = max(y, B);
        }

        if (A + B > N) cout << -1;
        else {
            for (int j = 0; j < A; j++) {
                cout << "a";
            }
            for (int j = 0; j < B; j++) {
                cout << "b";
            }
        }

        cout << "\n";
    }


    return 0;
}
