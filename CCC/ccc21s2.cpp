#include <bits/stdc++.h>

using namespace std;

int M, N, K, R = 0, C = 0;
// false: black, true: gold
bool r[5000000], c[5000000];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        char ch; int k; cin >> ch >> k;
        switch (ch) {
            case 'R': {
                r[k - 1] = !r[k - 1];
                break;
            }
            case 'C': {
                c[k - 1] = !c[k - 1];
                break;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        if (r[i]) R++;
    }

    for (int i = 0; i < N; i++) {
        if (c[i]) C++;
    }

    cout << N * R + M * C - 2 * R * C;

    return 0;
}
