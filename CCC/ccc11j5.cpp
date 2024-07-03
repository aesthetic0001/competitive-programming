#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int N;

// this is a tree data struct, directed
// node u depends on v
vector<int> T[7];
int ways[7];

int dfs(int u) {
    if (T[u].empty()) return ways[u] = 2;
    for (const auto &v : T[u]) {
        ways[u] *= dfs(v);
    }
    return ways[u] + 1;
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;

    for (int u = 1; u <= N - 1; u++) {
        int v; cin >> v;
        T[v].emplace_back(u);
        ways[u] = 1;
    }

    // root the tree at N
    ways[N] = 1;
    dfs(N);

    // for (int i = 1; i <= N; i++) {
    //     cout << i << " " << ways[i] << "\n";
    // }

    cout << ways[N];

    return 0;
}
