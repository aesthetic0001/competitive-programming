#include <bits/stdc++.h>

using namespace std;

signed main() {
    int rw, rh, cw, ch, steps;
    cin >> rw >> rh >> cw >> ch >> steps;
//    YX system rather than XY
    bool vis[rh + 2][rw + 2];

    const int lwc = cw;
    const int lhc = ch;
    const int rwc = rw - cw + 1;
    const int rhc = rh - ch + 1;

    for (int i = 0; i <= rh + 1; i++) {
        for (int j = 0; j <= rw + 1; j++) {
            if (i == 0 || j == 0 || i == rh + 1 || j == rw + 1) {
                vis[i][j] = true;
            } else if ((j <= lwc && i <= lhc) || (j >= rwc && i >= rhc) || (j <= lwc && i >= rhc) || (j >= rwc && i <= lhc)) {
                vis[i][j] = true;
            } else {
                vis[i][j] = false;
            }
        }
    }

    // for (int i = 0; i <= rh + 1; i++) {
    //     for (int j = 0; j <= rw + 1; j++) {
    //         if (vis[i][j]) {
    //             cout << "X";
    //         } else {
    //             cout << "O";
    //         }
    //     }
    //     cout << "\n";
    // }

    int curX = cw + 1, curY = 1;
    // u, d, l, r
    char dir = 'r';

    while (steps) {
        bool moved = true;
        vis[curY][curX] = true;
        switch (dir) {
            case 'r': {
                // check order: up, right, down, left
                if (!vis[curY - 1][curX]) {
                    curY--;
                    dir = 'u';
                } else if (!vis[curY][curX + 1]) {
                    curX++;
                    dir = 'r';
                } else if (!vis[curY + 1][curX]) {
                    curY++;
                    dir = 'd';
                } else if (!vis[curY][curX - 1]) {
                    curX--;
                    dir = 'l';
                } else {
                    moved = false;
                }
                break;
            }
            case 'd': {
                // right, down, left, up
                if (!vis[curY][curX + 1]) {
                    curX++;
                    dir = 'r';
                } else if (!vis[curY + 1][curX]) {
                    curY++;
                    dir = 'd';
                } else if (!vis[curY][curX - 1]) {
                    curX--;
                    dir = 'l';
                } else if (!vis[curY - 1][curX]) {
                    curY--;
                    dir = 'u';
                } else {
                    moved = false;
                }
                break;
            }
            case 'l': {
                // check order: down, left, up, right
                if (!vis[curY + 1][curX]) {
                    curY++;
                    dir = 'd';
                } else if (!vis[curY][curX - 1]) {
                    curX--;
                    dir = 'l';
                } else if (!vis[curY - 1][curX]) {
                    curY--;
                    dir = 'u';
                } else if (!vis[curY][curX + 1]) {
                    curX++;
                    dir = 'r';
                } else {
                    moved = false;
                }
                break;
            }
            case 'u': {
                // right, down, left, up
                if (!vis[curY][curX - 1]) {
                    curX--;
                    dir = 'l';
                } else if (!vis[curY - 1][curX]) {
                    curY--;
                    dir = 'u';
                } else if (!vis[curY][curX + 1]) {
                    curX++;
                    dir = 'r';
                } else if (!vis[curY + 1][curX]) {
                    curY++;
                    dir = 'd';
                } else {
                    moved = false;
                }
                break;
            }
        }
        if (!moved) {
            break;
        }
        steps--;
    }

    // for (int i = 1; i <= rh; i++) {
    //     for (int j = 1; j <= rw; j++) {
    //         if (vis[i][j]) {
    //             cout << "X";
    //         } else {
    //             cout << "O";
    //         }
    //     }
    //     cout << "\n";
    // }

    cout << curX << "\n" << curY;

    return 0;
}
