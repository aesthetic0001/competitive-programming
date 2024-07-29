#include <bits/stdc++.h>

using namespace std;

int N, X; bool parity[1000000];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N >> X;

    // cannot be different parity
    if (X % 2 != N % 2) {
        cout << -1 << "\n";
        return 0;
    }

    int iters = N - X;
    for (int i = 0; i < iters; i += 2) {
        parity[i] = true;
    }

    for (int i = 0; i < N; i++) {
        cout << (parity[i] ? "1" : "2") << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
