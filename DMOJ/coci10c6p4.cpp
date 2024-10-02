#include <bits/stdc++.h>
#include <unordered_map>

// #define int unsigned long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N;
unordered_set<char> letters, vis;
unordered_map<char, unordered_set<char>> graph;
unordered_map<char, int> in;
vector<string> words;
string ans;
queue<char> q;

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
        in[c] = 0;
      }
    }

    for (int i = 0; i < words.size(); i++) {
      string &higher = words[i];
      for (int j = i + 1; j < words.size(); j++) {
        string &lower = words[j];
        int ct = 0;
        while (ct < min(higher.size(), lower.size()) && higher[ct] == lower[ct]) {
          ct++;
        }
        if (ct < higher.size() && ct < lower.size() && graph[higher[ct]].find(lower[ct]) == graph[higher[ct]].end()) {
          printf("relation between %c and %c\n", higher[ct], lower[ct]);
          graph[higher[ct]].emplace(lower[ct]);
          in[lower[ct]] += 1;
        }
      }
    }

    // perform toposort
    for (const auto &[c, indeg] : in) {
      // printf("%c %d\n", c, indeg);
      if (indeg == 0) {
        cout << "potentially start at " << c << '\n';
        q.emplace(c);
      }
    }

    // no starting point. cyclic
    if (q.size() == 0) {
      cout << '!';
      return 0;
    }
    // ambiguous starting point
    if (q.size() > 1) {
      cout << '?';
      return 0;
    }

    while (!q.empty()) {
      const auto top = q.front(); q.pop();
      bool done = false;

      ans += top;

      for (const auto &adj : graph[top]) {
        in[adj] -= 1;
        if (in[adj] == 0) {
          if (done) {
            // ambiguous next node
            cout << '?';
            return 0;
          }
          q.emplace(adj);
          done = true;
        }
      }
    }
    
    // indeterminate
    if (ans.size() != letters.size()) {
      cout << '!';
      return 0;
    }

    cout << ans;

    return 0;
}

