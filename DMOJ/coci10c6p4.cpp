#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N;
unordered_set<char> letters, graph[26];
bool vis[26];
vector<char> ans;
vector<string> words;
queue<char> q;

int bfs(char source, char target) {
  for (int i = 0; i < 26; i++) {
    vis[i] = false;
  }
  q.emplace(source);
  while (!q.empty()) {
    const auto top = q.front(); q.pop();
    // printf("vis %c from %c\n", top, source);
    // source > target
    if (top == target) return 1;
    for (const auto &adj : graph[int(top - 'a')]) {
      // printf("adj of %c: %c\n", adj, top);
      if (adj == source) return -1;
      if (vis[int(adj - 'a')]) continue;
      vis[int(adj - 'a')] = true;
      q.emplace(adj);
    }
  }
  return 0;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
      string s; cin >> s;
      words.emplace_back(s);
      for (const auto &c : s) {
        letters.emplace(c);
      }
      // cout << s << '\n';
    }

    // cout << "end\n";

    for (int i = 0; i < words.size(); i++) {
      string &higher = words[i];
      for (int j = i + 1; j < words.size(); j++) {
        string &lower = words[j];
        int ct = 0;
        while (ct < min(higher.size(), lower.size()) && higher[ct] == lower[ct]) {
          ct++;
        }
        if (ct == min(higher.size(), lower.size()) && higher[ct - 1] == lower[ct - 1] && lower.size() > higher.size()) {
          printf("!");
          return 0;
        }
        if (ct < higher.size() && ct < lower.size()) {
          // printf("valid relation: %c %c\n", higher[ct], lower[ct]);
          graph[int(higher[ct] - 'a')].emplace(lower[ct]);
        }
      }
    }

    // no possibilities case
    for (const auto &c : letters) {
      if (bfs(c, 'A') == -1) {
        printf("!");
        return 0;
      }
    }

    for (const auto &a : letters) {
      for (const auto &b : letters) {
        if (a == b) continue;
        if (bfs(a, b) == 0 && bfs(b, a) == 0) {
          // printf("indeterminate relationship: %c %c\n", a, b);
          printf("?");
          return 0;
        }
      }
    }

    for (const auto &c : letters) {
      ans.emplace_back(c);
    }

    // at this point, it is valid. we just need to sort.
    sort(ans.begin(), ans.end(), [](auto a, auto b) {
        bool res = (bfs(a, b) == 1);
        printf("%c %c res: %d\n", a, b, res);
        return res;
    });

    for (const auto &c : ans) {
      printf("%c", c);
    }

    return 0;
}

