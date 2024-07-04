#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

namespace std {
    template <>
    struct hash<pair<double, double>> {
        size_t operator()(const pair<double, double> &x) const {
            return hash<double>()(x.first) ^ hash<double>()(x.second);
        }
    };
}

char grid[8][8];
vector<pair<int, int>> t;
vector<pair<int, int>> dirs = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int ans = 0;

void recurse(int x, int y, int captures = 0) {
    ans = max(captures, ans);
    for (const auto &[dx, dy] : dirs) {
        if (x + 2 * dx < 0 || x + 2 * dx >= 8 || y + 2 * dy < 0 || y + 2 * dy >= 8) continue;
        if (grid[x + dx][y + dy] == 'B' && grid[x + 2 * dx][y + 2 * dy] == '.') {
            grid[x][y] = '.';
            grid[x + dx][y + dy] = '.';
            grid[x + 2 * dx][y + 2 * dy] = 'A';
            recurse(x + 2 * dx, y + 2 * dy, captures + 1);
            grid[x][y] = 'A';
            grid[x + dx][y + dy] = 'B';
            grid[x + 2 * dx][y + 2 * dy] = '.';
        }
    }
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') t.emplace_back(i, j);
        }
    }

    for (const auto &[x, y] : t) recurse(x, y);

    cout << ans;

    return 0;
}
