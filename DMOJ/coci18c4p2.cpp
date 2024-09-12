#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N, M, ans[100001];
bool vis = false;
vector<int> graph[100001];
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        int X, Y; scanf("%d %d", &X, &Y);
        graph[Y].eb(X);
    }

    q.em(1);

    while (!q.empty()) {
        const int top = q.front(); q.pop();
        for (const auto &v : graph[top]) {
            if (!ans[v]) {
                vis = true;
                ans[v] = 1;
                q.em(v);
            }
        }
    }

    if (!vis) {
        ans[1] = true;
    }

    for (int i = 1; i <= N; i++) {
        printf("%d", ans[i]);
    }

    return 0;
}
