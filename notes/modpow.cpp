#include <iostream>

#define MOD 1000000007
#define INT long long

int modPow(int a, int b) {
  printf("%d %d\n", a, b);
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
    std::cout << modPow(2, 3);
    return 0;
}
