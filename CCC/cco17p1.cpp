#include <bits/stdc++.h>

using namespace std;

int K, V = 0;

vector<pair<int, int>> ans;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> K;

    while (K != 0) {
        if (V != 0) {
            // singly linked
            ans.emplace_back(V, V + 1);
        }
        int n = floor((1.f + sqrt(1.f + (8 * K))) / 2.f);
        int reduction = (n * (n - 1)) / 2;

        // cout << "DBG: " << n << " " << reduction << "\n";

        for (int i = V + 1; i <= V + n - 1; i++) {
            ans.emplace_back(i, i + 1);
        }

        ans.emplace_back(V + n, V + 1);

        V += n;
        K -= reduction;
    }

    cout << V << " " << ans.size() << "\n";

    for (const auto &[a, b] : ans) {
        cout << a << " " << b << "\n";
    }

    return 0;
}
