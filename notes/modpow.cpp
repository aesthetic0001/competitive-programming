#include <iostream>

#define MOD 1000000007
#define int long long

int modPow(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        int ans = modPow(a * a % MOD, b / 2);
        if (b % 2 == 1) {
            ans = ans * a % MOD;
        }
        return ans;
    }
}

signed main() {
    std::cout << modPow(31, MOD - 2);
    return 0;
}
