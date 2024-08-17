#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    for (int i = 0; i < 10; i++) {
        int N, M, D, ans = 0; unordered_map<int, int> events;
        cin >> N >> M >> D;

        for (int j = 0; j < M; j++) {
            int k; cin >> k; events[k]++;
        }

        int curShirts = N;

        for (int j = 1; j <= D; j++) {
            if (curShirts == 0) {
                ans++;
                curShirts = N;
            }
            curShirts--;
            if (events.find(j) != events.end()) {
                N += events[j];
                curShirts += events[j];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
