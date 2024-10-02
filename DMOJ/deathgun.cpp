#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, ct = 0, in[900];
unordered_set<int> graph[900];
unordered_map<string, int> skibidi;
vector<string> sigma;
priority_queue<int, vector<int>, greater<int>> pq;

int compstr(string s) {
  if (skibidi.find(s) == skibidi.end()) {
    skibidi[s] = ct;
    sigma.emplace_back(s);
    ct += 1;
  }
  return skibidi[s];
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin >> N;

    for (int i = 0; i < N; i++) {
      string u, v; cin >> u >> v;
      int ui = compstr(u), vi = compstr(v);
      graph[vi].emplace(ui);
      in[ui] += 1;
    }

    // toposort
    for (int i = 0; i < sigma.size(); i++) {
      if (in[i] == 0) {
        pq.emplace(i);
      }
    }

    while (!pq.empty()) {
      const int top = pq.top(); pq.pop();
      cout << sigma[top] << '\n';
      for (const auto &v : graph[top]) {
        in[v] -= 1;
        if (in[v] == 0) {
          pq.emplace(v);
        }
      }
    }

    return 0;
}

