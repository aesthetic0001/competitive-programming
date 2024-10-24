#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

string N, H;
unordered_set<int> vis;
int need[26], cur[26];
int rolling[200001], rolling2[200001];
int MOD = 1000000007, base = 31, base2 = 29;

inline int modpow(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int ans = modpow((a * a) % MOD, b / 2);
  if (b % 2 == 1) {
    ans = (ans * a) % MOD;
  }
  return ans % MOD;
}

inline int h_substr(int l, int r) {
  int rel = ((rolling[r + 1] - rolling[l]) % MOD + MOD) % MOD;
  int rel2 = ((rolling2[r + 1] - rolling2[l]) % MOD + MOD) % MOD;
  int off = modpow(base, H.size() - l);
  int off2 = modpow(base2, H.size() - l);
  return ((rel2 * off2 % MOD) << 31) | (rel * off % MOD);
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

inline void polyhash(int base, int* rolling) {
  int power = 1;
  for (int i = 0; i < H.size(); i++) {
    int charhash = (power * (H[i] - 'a' + 1)) % MOD;
    rolling[i + 1] = (rolling[i] + charhash) % MOD;
    power = (power * base) % MOD;
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

    polyhash(base, rolling);
    polyhash(base2, rolling2);

    check(0);

    for (int i = 1; i <= H.size() - N.size(); i++) {
      cur[H[i - 1] - 'a'] -= 1;
      cur[H[i + N.size() - 1] - 'a'] += 1;
      check(i);
    }

    cout << vis.size();

    return 0;
}

