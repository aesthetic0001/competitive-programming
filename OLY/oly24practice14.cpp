#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

string N; int ans = 1;
const int MOD = 1000000007;

int modpow(int base, int exp) {
    if (exp == 0) return 1;
    int res = modpow((base * base) % MOD, exp / 2);
    if (exp & 1) {
        res *= base; res %= MOD;
    }
    return res;
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    int r = modpow(10, N.size());
    int n = stol(N);

    ans *= n; ans %= MOD;
    ans *= modpow(r, n) - 1; ans %= MOD;
    ans *= modpow(r - 1, MOD - 2); ans %= MOD;

    cout << ans;

    return 0;
}
