#include <bits/stdc++.h>
#include <unordered_set>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

// topo sort
int N;

unordered_set<int> graph[200001];
vector<int> ans;
bool vis[200001];

void topo(int node) {
    vis[node] = true;

    for (const auto &adj : graph[node]) {
        if (!vis[adj]) {
            topo(adj);
        }
    }

    ans.emplace_back(node);
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        int k; scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int m; scanf("%d", &m);
            graph[i].emplace(m);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            topo(i);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
