#include <bits/stdc++.h>

using namespace std;

int N, M;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (M == 0) break;
            cout << i << " " << j << "\n";
            M--;
        }
        if (M == 0) break;
    }

    return 0;
}
