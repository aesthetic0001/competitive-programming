#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int p[100001], sz[100001], r[100001];
int N, M, K, ans = 0;

inline int query(int u) {
    if (p[u] == u) return u;
    return p[u] = query(p[u]);
}

inline void join(int u, int v) {
    int a = query(u);
    int b = query(v);

    if (a != b && r[a] == r[b]) {
        if (sz[a] < sz[b]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}

inline void mk(int u) {
    p[u] = u;
    sz[u] = 1;
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        mk(i);
        char k; cin >> k;
        switch (k) {
            case 'P': {
                r[i] = 1;
                break;
            }
            case 'Z': {
                r[i] = 2;
                break;
            }
            case 'T': {
                r[i] = 3;
                break;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        join(u, v);
    }

    for (int i = 0; i < K; i++) {
        int u, v; cin >> u >> v;
        if (query(u) == query(v)) {
            ++ans;
        }
    }

    cout << ans;

    return 0;
}
