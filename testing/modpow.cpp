#include <stack>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cmath>

#define int long long
#define MOD 1000000007
#define MAX 1000001

int diff[MAX];

using namespace std;

int modPow(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        int ans = modPow(a * a % MOD, b / 2);
        if (b & 1) {
            ans = ans * a % MOD;
        }
        return ans;
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cout << modPow(2, MOD - 2);

    return 0;
}
