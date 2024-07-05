#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, M, ans;

unordered_set<int> vis;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N >> M;

    ans = ((M) * (1 + M)) / 2;

    for (int _ = 0; _ < N; _++) {
        int a; cin >> a;
        if (a > M || vis.find(a) != vis.end()) continue;
        vis.emplace(a);
        ans -= a;
    }

    cout << ans;

    return 0;
}
