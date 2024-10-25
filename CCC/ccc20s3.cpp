#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

string N, H;
unordered_set<int> vis;
int need[26], cur[26], r1[200001], r2[200001], p1[200000], p2[200000], MOD = 1000000007, base = 31, base2 = 29;

inline int h_substr(int l, int r) {
  int h1 = ((r1[r + 1] - r1[l]) * p1[H.size() - l] % MOD + MOD) % MOD;
  int h2 = ((r2[r + 1] - r2[l]) * p2[H.size() - l] % MOD + MOD) % MOD;
  return h1 ^ (h2 << 31);
}

inline void check(int l) {
  int hash = h_substr(l, l + N.size() - 1);
  if (vis.find(hash) != vis.end()) {
    return;
  }
  for (int i = 0; i < 26; i++) {
    if (need[i] != cur[i]) return;
  }
  vis.emplace(hash);
}

inline void polyhash(int base, int* rolling, int* powers) {
  powers[0] = 1;
  for (int i = 0; i < H.size(); i++) {
    int charhash = (powers[i] * (H[i] - 'a' + 1)) % MOD;
    rolling[i + 1] = (rolling[i] + charhash) % MOD;
    powers[i + 1] = (powers[i] * base) % MOD;
  }
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N >> H;

    if (N.size() > H.size()) {
      cout << 0;
      return 0;
    }

    for (const auto &c : N) {
      need[c - 'a'] += 1;
    }

    for (int i = 0; i < N.size(); i++) {
      cur[H[i] - 'a'] += 1;
    }

    polyhash(base, r1, p1);
    polyhash(base2, r2, p2);

    check(0);

    for (int i = 1; i <= H.size() - N.size(); i++) {
      cur[H[i - 1] - 'a'] -= 1;
      cur[H[i + N.size() - 1] - 'a'] += 1;
      check(i);
    }

    cout << vis.size();

    return 0;
}
