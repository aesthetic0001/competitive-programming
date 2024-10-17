#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, letterpos[26], indeg[26];
vector<string> words;
unordered_map<string, int> stoidx;
unordered_set<int> graph[26], tovis;
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < 26; i++) {
      letterpos[i] = i;
    }

    for (int i = 0; i < N; i++) {
      string s; cin >> s;
      words.emplace_back(s);
    }

    for (int i = 0; i < N; i++) {
      int ord; cin >> ord;
      stoidx[words[ord - 1]] = i;
    }

    sort(words.begin(), words.end(), [&](string &a, string &b) {
        return stoidx[a] < stoidx[b];
    });

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        // s1 should be lexicographically smaller than s2 (ie. it should appear earlier than s2)
        string &s1 = words[i];
        string &s2 = words[j];

        int ct = 0;

        while (ct < min(s1.size(), s2.size()) && s1[ct] == s2[ct]) {
          ct += 1;
        }

        if (ct == min(s1.size(), s2.size()) && s1[ct - 1] == s2[ct - 1]) {
          if (s1.size() > s2.size()) {
            cout << "NE\n";
            return 0;
          }
          continue;
        }

        int idx1 = (int)(s1[ct]) - (int)('a');
        int idx2 = (int)(s2[ct]) - (int)('a');

        // cout << s1[ct] << " " << s2[ct] << '\n';

        // cout << idx1 << " " << idx2;

        if (graph[idx2].find(idx1) == graph[idx2].end()) {
          // idx2 should be smaller than idx1, so idx2 leads to idx1 (ie. we check if idx2 is too big, then we propagate upward)
          graph[idx2].emplace(idx1);
          indeg[idx1]++;
          tovis.emplace(idx1);
          tovis.emplace(idx2);
        }
      }
    }

    // topo sort
    for (int i = 0; i < 26; i++) {
      if (indeg[i] == 0) {
        q.emplace(i);
      }
    }

    while (!q.empty()) {
      const auto top = q.front(); q.pop();
      tovis.erase(top);

      for (const auto &adj : graph[top]) {
        indeg[adj] -= 1;
        // cout << letterpos[top] << " " << letterpos[adj] << "\n";
        if (letterpos[top] < letterpos[adj]) {
          // swap them
          int t1 = letterpos[top], t2 = letterpos[adj];
          letterpos[top] = t2;
          letterpos[adj] = t1;
        }
        if (indeg[adj] == 0) {
          q.emplace(adj);
        }
      }
    }

    if (!tovis.empty()) {
      cout << "NE\n";
      return 0;
    }

    cout << "DA\n";

    for (int i = 0; i < 26; i++) {
      cout << (char)((int)'a' + letterpos[i]);
    }

    cout << "\n";

    return 0;
}
