#include <bits/stdc++.h>
#include <tuple>

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

int N, dis[1002][1002];
bool solved = false, grid[1002][1002];
queue<tuple<int, int, int, int, int>> q;

inline int cost(int D, int L, int R) {
    return pow(D, 2) + pow(L, 2) + pow(R, 2);
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld", &N);

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            dis[i + 1][j + 1] = INT64_MAX;
            grid[i + 1][j + 1] = s[j] == '.';
        }
    }

    dis[1][1] = 0;
    q.em(forward_as_tuple(1, 1, 0, 0, 0));

    while (!q.empty()) {
        const auto [r, c, D, L, R] = q.front(); q.pop();

        if (grid[r + 1][c] && dis[r + 1][c] > cost(D + 1, L, R)) {
            dis[r + 1][c] = cost(D + 1, L, R);
            q.em(forward_as_tuple(r + 1, c, D + 1, L, R));
        }
        if (grid[r][c + 1] && dis[r][c + 1] > cost(D, L, R + 1)) {
            dis[r][c + 1] = cost(D, L, R + 1);
            q.em(forward_as_tuple(r, c + 1, D, L, R + 1));
        }
        if (grid[r][c - 1] && dis[r][c - 1] > cost(D, L + 1, R)) {
            dis[r][c - 1] = cost(D, L + 1, R);
            q.em(forward_as_tuple(r, c - 1, D, L + 1, R));
        }
    }

    printf("%lld", (dis[N][N] == INT64_MAX ? -1 : dis[N][N]));

    return 0;
}
