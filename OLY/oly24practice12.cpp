#include <bits/stdc++.h>

#define int long long

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

unordered_map<int, int> memo;

int recurse(int n) {
    if (n == 1) return 0;
    if (memo.find(n) != memo.end()) return memo[n];

    if (n % 2 == 0) {
        return memo[n] = (n + 2 * recurse(n / 2));
    } else {
        return memo[n] = (n + recurse((n - 1) / 2) + recurse(((n - 1) / 2) + 1));
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    int N; cin >> N;

    cout << recurse(N);

    return 0;
}
