#include <bits/stdc++.h>

using namespace std;

char _;

signed main() {
    // freopen("sample.in", "r", stdin);
    cin.tie(0); cin.sync_with_stdio(0);

    int G, P; cin >> G >> P;

    int ans = 0;

    set<int> ok;

    for (int i = 1; i <= G; i++) ok.emplace(i);

    for (int i = 0; i < P; i++) {
        int g; cin >> g;
        auto res = ok.upper_bound(g);
        if (res == ok.begin()) break;
        --res;
        ok.erase(res);
        ++ans;
    }

    cout << ans;
    return 0;
}
