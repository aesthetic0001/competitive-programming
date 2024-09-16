#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, in[10001];
unordered_set<int> graph[10001];
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (graph[a].find(b) == graph[a].end()) {
            graph[a].emplace(b);
            in[b] += 1;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (in[i] == 0) {
            q.emplace(i);
        }
    }

    int ct = 0;

    while (!q.empty()) {
        const int top = q.front(); q.pop();
        ct++;
        for (const auto &adj : graph[top]) {
            in[adj] -= 1;
            if (in[adj] == 0) {
                q.emplace(adj);
            }
        }
    }

    if (ct == N) printf("Y");
    else printf("N");

    return 0;
}
