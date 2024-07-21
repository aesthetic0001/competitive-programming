#include <bits/stdc++.h>

using namespace std;

int N, ans, len, occurrences[2001], L[4001];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    for (int _ = 0, l; _ < N; _++) {
        cin >> l; occurrences[l]++;
    }

    for (int i = 1; i <= 2000; i++) {
        for (int j = i; j <= 2000; j++) {
            L[i + j] += ((i == j) ? (occurrences[i] / 2) : (min(occurrences[i], occurrences[j])));
        }
    }

    for (int i = 2; i <= 4000; i++) {
        if (L[i] > ans) {
            ans = L[i];
            len = 1;
        } else if (L[i] == ans) {
            len++;
        }
    }

    cout << ans << " " << len;

    return 0;
}
