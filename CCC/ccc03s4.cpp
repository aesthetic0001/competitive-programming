#include <bits/stdc++.h>

#define int long long

using namespace std;

int N, r1[5000], r2[5000], p1[5000], p2[5000], MOD = 1000000007, base1 = 31, base2 = 29;
string s;

inline int h_substr(int l, int r) {
  int h1 = ((r1[r + 1] - r1[l]) * p1[s.size() - l] % MOD + MOD) % MOD;
  int h2 = ((r2[r + 1] - r2[l]) * p2[s.size() - l] % MOD + MOD) % MOD;
  return h1 + (h2 << 31);
}

inline void polyhash(int base, int* rolling, int* powers) {
  powers[0] = 1;
  for (int i = 0; i < s.size(); i++) {
    int charhash = (powers[i] * (s[i] - 'a' + 1)) % MOD;
    rolling[i + 1] = (rolling[i] + charhash) % MOD;
    powers[i + 1] = (powers[i] * base) % MOD;
  }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> N;
    while (N--) {
        cin >> s;
        unordered_set<int> found;
        for (int i = 0; i < 5000; i++) {
            r1[i] = 0; r2[i] = 0; p1[i] = 0; p2[i] = 0;
        }
        polyhash(base1, r1, p1);
        polyhash(base2, r2, p2);
        for (int sz = 1; sz <= s.size(); sz++) {
            for (int start = 0; start <= s.size() - sz; start++) {
                int substr = h_substr(start, start + sz - 1);
                if (found.find(substr) == found.end()) {
                    found.emplace(substr);
                }
            }
        }
        cout << found.size() + 1 << '\n';
    }
    return 0;
}
