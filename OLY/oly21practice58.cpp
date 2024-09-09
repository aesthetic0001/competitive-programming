#include <bits/stdc++.h>

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

int N, K, cycleStart, cycleSz, pathSz = 0, to[200001], vis[200001], dis[200001];
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

        if (vis[to[top]]) {
            // printf("cycle detected at %lld to %lld: size of %lld\n", top, to[top], dis[top] - dis[to[top]] + 1);
            cycleSz = dis[top] - dis[to[top]] + 1;
            cycleStart = to[top];
            break;
        }

        vis[top] = true;
        // printf("vis %lld\n", top);
        if (dis[top] + 1 < dis[to[top]]) {
            dis[to[top]] = dis[top] + 1;
            q.em(to[top]);
        }
    }

    pathSz--;

    // printf("path sz: %lld | cycle sz: %lld | start: %lld\n", pathSz, cycleSz, cycleStart);

    // for (int i = 1; i <= N; i++) {
    //     printf("%lld: %lld\n", i, dis[i]);
    // }

    if (K < pathSz - cycleSz) {
        // printf("sigma? %lld %lld\n", K, pathSz - cycleSz);
        for (int i = 1; i <= N; i++) {
            if (dis[i] == K) {
                printf("%lld", i);
                break;
            }
        }
    } else {
        K -= pathSz - cycleSz;
        K %= 3;

        if (K == 0) K = cycleSz;

        // printf("skibidi: %lld want %lld\n", K, dis[cycleStart] + K - 1);

        for (int i = 1; i <= N; i++) {
            if (dis[i] == dis[cycleStart] + K - 1) {
                printf("%lld", i);
                break;
            }
        }
    }

    return 0;
}
