#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N, Q;
int psa[100001];

inline int query(int l, int r) {
    return psa[r] - psa[l - 1];
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }

    for (int i = 0; i < Q; i++) {
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        double q1 = query(l1, r1), q2 = query(l2, r2);
        double ans = 0;

        ans = max(q1 / 2 + min(10, static_cast<int>(q2)), q2 / 2 + min(10, static_cast<int>(q1)));

        cout << fixed << setprecision(1) << ans << '\n';
    }

    return 0;
}
