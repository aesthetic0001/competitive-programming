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

int R, C, T, sY, sX, eY, eX, dis[1001][1001];
queue<PII> q;
vector<PII> skibidi;
// true: empty
bool graph[1001][1001];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &R, &C);
    scanf("%d %d", &sY, &sX);
    scanf("%d %d", &eY, &eX);

    string s;

    for (int i = 0; i < R; i++) {
        cin >> s;
        for (int j = 0; j < C; j++) {
            graph[i][j] = s[j] == 'O';
            dis[i][j] = INT32_MAX;
        }
    }

    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        skibidi.eb(mp(r, c));
    }

    dis[sY][sX] = 0;
    q.em(mp(sY, sX));

    while (!q.empty()) {
        const auto [y, x] = q.front(); q.pop();

        if (y + 1 < R && graph[y + 1][x] && dis[y][x] + 1 < dis[y + 1][x]) {
            dis[y + 1][x] = dis[y][x] + 1;
            q.em(mp(y + 1, x));
        }

        if (y - 1 >= 0 && graph[y - 1][x] && dis[y][x] + 1 < dis[y - 1][x]) {
            dis[y - 1][x] = dis[y][x] + 1;
            q.em(mp(y - 1, x));
        }

        if (x + 1 < C && graph[y][x + 1] && dis[y][x] + 1 < dis[y][x + 1]) {
            dis[y][x + 1] = dis[y][x] + 1;
            q.em(mp(y, x + 1));
        }

        if (x - 1 >= 0 && graph[y][x - 1] && dis[y][x] + 1 < dis[y][x - 1]) {
            dis[y][x - 1] = dis[y][x] + 1;
            q.em(mp(y, x - 1));
        }
    }

    int bestTP = INT32_MAX;

    for (const auto &[y, x] : skibidi) {
        bestTP = min(bestTP, dis[y][x]);
    }

    assert(dis[eY][eX] != INT32_MAX);

    printf("%d", dis[eY][eX] - bestTP);

    return 0;
}
