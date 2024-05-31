#include <iostream>
#include <cmath>
#include <unordered_map>

#define ll long long

using namespace std;

ll N;
const ll MAX = 20e5;
// 1 indexed arrays
ll fenwick[MAX + 1];
ll B[MAX + 1];
ll ans = 0;

unordered_map<ll, ll> lastOccurence;


inline void updateFenwick(ll i, const ll v) {
    while (i <= N) {
        fenwick[i] += v;
        i += (i & -i);
    }
}

inline ll queryFenwick(ll i) {
    ll res = 0;

    while (i > 0) {
        res += fenwick[i];
        i -= (i & -i);
    }

    return res;
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> N;

    for (ll i = 1; i <= N; i++) {
        ll b;
        cin >> b;
        B[i] = b;
        fenwick[i] = 0;
        if (lastOccurence.find(b) == lastOccurence.end()) {
            // -1 indicates not occured
            lastOccurence[b] = -1;
        }
    }

    for (ll r = 1; r <= N; r++) {
        const auto &b = B[r];

        if (lastOccurence[b] != -1) {
            // need to remove the previous value from BIT
            updateFenwick(lastOccurence[b], -1);
        }

        updateFenwick(r, 1);

        // cout << "FEN START AT " << r << "\n";
        // for (ll i = 1; i <= N; i++) {
        //     cout << fenwick[i] << "\n";
        // }
        // cout << "FEN END\n";

        // cant form delegations if r is at index 1 because there will be no valid value for l
        if (r != 1) {
            const ll l = max(0ll, lastOccurence[b]);
            // the issue was here, should have been r - 1 and l - 1 because the value at r is inclusive.
            ans += queryFenwick(r - 1) - queryFenwick(l - 1);
        }

        lastOccurence[b] = r;
    }

    cout << ans;

    return 0;
}
