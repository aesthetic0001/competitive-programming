#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int R, C, ans = 0;
bool g[101][101], vis[101][101];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string s; cin >> s;
        for (int j = 0; j < C; j++) {
            g[i][j] = s[j] == 'X';
        }
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (g[i][j] || vis[i][j]) continue;
            q.emplace(i, j);
            while (!q.empty()) {
                const auto [a, b] = q.front(); q.pop();
                vis[a][b] = true;
                if (a - 1 >= 0 && !vis[a - 1][b] && !g[a - 1][b]) q.emplace(a - 1, b);
                if (a + 1 < R && !vis[a + 1][b] && !g[a + 1][b]) q.emplace(a + 1, b);
                if (b - 1 >= 0 && !vis[a][b - 1] && !g[a][b - 1]) q.emplace(a, b - 1);
                if (b + 1 < C && !vis[a][b + 1] && !g[a][b + 1]) q.emplace(a, b + 1);
            }
            ++ans;
        }
    }

    cout << ans;

    return 0;
}
