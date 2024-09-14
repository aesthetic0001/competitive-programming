#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, ans = 0, longest = 0;
queue<int> q;
vector<PII> graph[100001];
int dis[100001];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int a, b, w; scanf("%d %d %d", &a, &b, &w);
        dis[i + 1] = INT32_MAX;
        graph[a].emplace_back(make_pair(b, w));
        graph[b].emplace_back(make_pair(a, w));
    }

    q.emplace(0);
    dis[0] = 0;

    while (!q.empty()) {
        const int top = q.front(); q.pop();
        // printf("vis %d\n", top);

        for (const auto &[v, w] : graph[top]) {
            if (dis[top] + w < dis[v]) {
                dis[v] = dis[top] + w;
                longest = max(longest, dis[v]);
                ans += w * 2;
                q.emplace(v);
            }
        }
    }

    printf("%d", ans- longest);

    return 0;
}
