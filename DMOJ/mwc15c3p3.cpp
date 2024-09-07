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

int N, Q;

char sigma[27][27];
bool vis[27][27];

bool skibidi(int y, int x, string s, int idx) {
    vis[y][x] = true;
    if (idx == s.length() - 1) return true;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0) continue;
            if (sigma[y + dy][x + dx] == s[idx + 1] && !vis[y + dy][x + dx]) {
                if (skibidi(y + dy, x + dx, s, idx + 1)) return true;
            }
        }
    }

    return false;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d", &N, &Q);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf(" %c", &sigma[i][j]);
        }
    }

    for (int i = 0; i < Q; i++) {
        string s;
        bool done = false;
        cin >> s;

        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (sigma[y][x] == s[0]) {
                    for (int t1 = 0; t1 < 27; t1++) {
                        for (int t2 = 0; t2 < 27; t2++) {
                            vis[t1][t2] = false;
                        }
                    }
                    if (skibidi(y, x, s, 0)) {
                        printf("good puzzle!\n");
                        done = true;
                    }
                }
            }
            if (done) break;
        }

        if (!done) printf("bad puzzle!\n");
    }

    return 0;
}
