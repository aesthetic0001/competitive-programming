#include <bits/stdc++.h>
using namespace std;

#define mp(a,b) make_pair(a,b)
#define PSS pair<string, string>

string itostr[1001];
unordered_map<string, int> inv;
unordered_map<string, PSS> g;
unordered_map<string, pair<int, unordered_map<string, int>>> memo;

int ans = 0;

int dfs(string &v) {
  // If already computed
  if (memo.count(v)) {
    auto &[res, used] = memo[v];
    if (res == -1) return -1;
    for (auto &[k, val] : used) inv[k] -= val;
    ans++;
    return 1;
  }

  unordered_map<string, int> used;

  if (inv[v]) {
    inv[v]--;
    used[v]++;
    memo[v] = {1, used};
    ans++;
    return 1;
  }

  if (!g.count(v)) {
    memo[v] = {-1, {}};
    return -1;
  }

  auto &[l, r] = g[v];
  auto invBackup = inv;
  int prevAns = ans;

  if (dfs(r) == -1) {
    inv = invBackup;
    ans = prevAns;
    memo[v] = {-1, {}};
    return -1;
  }

  if (dfs(l) == -1) {
    inv = invBackup;
    ans = prevAns;
    memo[v] = {-1, {}};
    return -1;
  }

  for (const auto &item : invBackup) {
    if (inv[item.first] < item.second) {
      used[item.first] = item.second - inv[item.first];
    }
  }

  memo[v] = {1, used};
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  int a, b;
  cin >> s >> a >> b;
  for (int i = 0; i < a; i++){
      cin >> itostr[i];
  }
  for (int i = 0; i < a; i++){
      cin >> inv[itostr[i]];
  }
  for (int i = 0; i < b; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    g[c] = mp(a, b);
  }
  if (dfs(s) == -1) {
    cout << -1;
    return 0;
  }
  cout << ans;
  return 0;
}
