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

int sigma1[1501][1501], sigma2[1501][1501], alpha[1501][1501];
int N, M, K;
vector<tuple<int, int, int>> skibidi;
queue<PII> enigma;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d %d %d", &N, &M, &K);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &sigma1[i][j]);
            sigma2[i][j] = sigma1[i][j];
            alpha[i][j] = INT32_MAX;
            if (sigma1[i][j] != 0) {
                skibidi.eb(forward_as_tuple(sigma1[i][j], i, j));
            }
        }
    }

    sort(skibidi.begin(), skibidi.end());

    for (const auto &[_, y, x] : skibidi) {
        alpha[y][x] = 0;
        enigma.em(mp(y, x));

        while (!enigma.empty()) {
            const auto [cy, cx] = enigma.front(); enigma.pop();
            const int newD = alpha[cy][cx] + 1;

            if (newD > K) continue;

            if (cy - 1 >= 0 && sigma1[cy - 1][cx] == 0 && newD < alpha[cy - 1][cx]) {
                sigma2[cy - 1][cx] = sigma1[y][x];
                alpha[cy - 1][cx] = newD;
                enigma.em(mp(cy - 1, cx));
            }

            if (cy + 1 < N && sigma1[cy + 1][cx] == 0 && newD < alpha[cy + 1][cx]) {
                sigma2[cy + 1][cx] = sigma1[y][x];
                alpha[cy + 1][cx] = newD;
                enigma.em(mp(cy + 1, cx));
            }

            if (cx - 1 >= 0 && sigma1[cy][cx - 1] == 0 && newD < alpha[cy][cx - 1]) {
                sigma2[cy][cx - 1] = sigma1[y][x];
                alpha[cy][cx - 1] = newD;
                enigma.em(mp(cy, cx - 1));
            }

            if (cx + 1 < M && sigma1[cy][cx + 1] == 0 && newD < alpha[cy][cx + 1]) {
                sigma2[cy][cx + 1] = sigma1[y][x];
                alpha[cy][cx + 1] = newD;
                enigma.em(mp(cy, cx + 1));
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j != M - 1) printf("%d ", sigma2[i][j]);
            else printf("%d\n", sigma2[i][j]);
        }
    }

    return 0;
}
