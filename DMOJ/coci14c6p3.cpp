#include <bits/stdc++.h>
#include <cassert>
#include <cstdint>

using namespace std;

int R, C;

char photo[3000][3000], ans[3000][3000];

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> R >> C;


    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> photo[i][j];
        }
    }

    int maxShift = INT32_MAX;

    for (int col = 0; col < C; col++) {
        int meteor = -9999999, ground = R - 1;
        for (int i = 0; i < R; i++) {
            if (photo[i][col] == 'X') meteor = i;
        }
        for (int i = R - 1; i >= 0; i--) {
            if (photo[i][col] == '#') ground = i;
        }
        maxShift = min(maxShift, ground - meteor - 1);
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (photo[i][j] == 'X') {
                ans[i + maxShift][j] = 'X';
            } else if (photo[i][j] == '#') {
                ans[i][j] = '#';
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << (ans[i][j] ? ans[i][j] : '.');
        }
        cout << "\n";
    }

    return 0;
}
