#include <bits/stdc++.h>

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
        int meteor = -1, ground = R - 1;
        for (int i = 0; i < R; i++) {
            // must be connected
            if (meteor != -1 && photo[i][col] != 'X') break;
            if (photo[i][col] == 'X') {
                meteor = i;
            }
        }
        for (int i = R - 1; i >= 0; i--) {
            if (ground != R - 1 && photo[i][col] != '#') break;
            if (photo[i][col] == '#') {
                ground = i;
            }
        }
        // cout << ground << " " << meteor << " " << col << "\n";
        maxShift = min(maxShift, ground - meteor - 1);
    }

    // cout << maxShift;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (photo[i][j] == 'X') {
                // cout << "on skib bro\n";
                ans[i + maxShift][j] = 'X';
                ans[i][j] = '.';
            } else if (!ans[i][j]) {
                ans[i][j] = photo[i][j];
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}
