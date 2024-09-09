#include <bits/stdc++.h>
#include <cassert>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N, K, cycleStart, cycleSz, pathSz = 0, to[200001], dis[200001];
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld %lld", &N, &K);

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &to[i]);
        dis[i] = INT32_MAX;
    }

    q.em(1);
    dis[1] = 0;

    while (!q.empty()) {
        const int top = q.front(); q.pop();
        pathSz++;

        if (dis[to[top]] != INT32_MAX) {
            cycleSz = dis[top] - dis[to[top]] + 1;
            cycleStart = to[top];
            break;
        }

        if (dis[top] + 1 < dis[to[top]]) {
            dis[to[top]] = dis[top] + 1;
            q.em(to[top]);
        }
    }

    pathSz--;

    if (pathSz == 0) {
        printf("%lld", (int)1);
        return 0;
    }

    if (K < pathSz - cycleSz) {
        for (int i = 1; i <= N; i++) {
            if (dis[i] == K) {
                printf("%lld", i);
                break;
            }
        }
    } else {
        K -= pathSz - cycleSz;
        K %= cycleSz;

        if (K == 0) K = cycleSz;

        for (int i = 1; i <= N; i++) {
            if (dis[i] == dis[cycleStart] + K - 1) {
                printf("%lld", i);
                break;
            }
        }
    }

    return 0;
}
