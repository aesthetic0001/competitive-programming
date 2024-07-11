#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

// bruteforce sol - will TLE on 3rd sub
int N, c[100000], sieve[1000001]; unordered_map<int, int> nums;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> c[i];
        nums[c[i]] += 1;
    }

    for (const auto &[k, v] : nums) {
        for (int i = k; i <= 1000000; i += k) {
            sieve[i] += v;
        }
    }

    for (int i = 0; i < N; i++) cout << (sieve[c[i]] - 1) << "\n";

    return 0;
}
