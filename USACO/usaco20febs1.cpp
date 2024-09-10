#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;

int N, M, K, initial[100001], to[100001], vis[100001], ans[100001];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= N; i++) {
        initial[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int L, R;
        scanf("%d %d", &L, &R);

        for (int j = L; j < L + floor((double)(R - L + 1) / (double)2); j++) {
            int newLeft = initial[R - (j - L)];
            int newRight = initial[j];
            initial[j] = newLeft;
            initial[R - (j - L)] = newRight;
        }
    }

    for (int i = 1; i <= N; i++) {
        to[initial[i]] = i;
    }

    // this only goes through every single node once
    // maximum O(N + K MOD(200))
    for (int p = 1; p <= N; p++) {
        if (vis[p]) continue;
        int setsz = 1;
        int cur = p;
        vis[p] = true;

        while (to[cur] != p) {
            setsz++;
            cur = to[cur];
            vis[cur] = true;
        }

        // printf("sz: %d\n", setsz);

        int offset = K % setsz;
        cur = p;

        for (int i = 0; i < offset; i++) {
            cur = to[cur];
        }

        int ref = p;

        for (int i = 0; i < setsz; i++) {
            ans[cur] = ref;

            cur = to[cur];
            ref = to[ref];
        }
    }

    for (int i = 1; i <= N; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}
