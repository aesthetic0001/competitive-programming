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

int N, table[101][101];

bool check() {
    bool ok = true;

    for (int j = 0; j < N; j++) {
        int prev = table[0][j];
        if (!ok) break;
        for (int i = 0; i < N; i++) {
            if (prev > table[i][j] || (j > 0 && table[i][j - 1] >= table[i][j])) {
                ok = false;
                break;
            }
        }
    }
    return ok;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    while (true) {
        if (check()) break;
        int temp[101][101];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[j][N - i - 1] = table[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                table[i][j] = temp[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
