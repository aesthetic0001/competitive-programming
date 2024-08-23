#include <bits/stdc++.h>

using namespace std;

bool ans[2001][2001], special = false;
int N, M, R, C;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N >> M >> R >> C;

    // more complex method to not have interference
    if (R == N) {
        if (M % 2 == 1) {
            // odd - can form every combo
            if (C % 2 == 1) {
                for (int i = 0; i < ((M - C) / 2); i++) {
                    ans[N - 1][i] = true;
                    ans[N - 1][M - i - 1] = true;
                }
            } else {
                for (int i = 0; i < ((M - C - 1) / 2); i++) {
                    ans[N - 1][i] = true;
                    ans[N - 1][M - i - 1] = true;
                }
                ans[N - 1][(M - 1) / 2] = true;
            }
        } else {
            // even - only even C are possible
            if (C % 2 == 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
            for (int i = 0; i < ((M - C) / 2); i++) {
                ans[N - 1][i] = true;
                ans[N - 1][M - i - 1] = true;
            }
        }
    } else if (C == M) {
        if (N % 2 == 1) {
            // odd - can form every combo
            if (R % 2 == 1) {
                for (int i = 0; i < ((N - R) / 2); i++) {
                    ans[i][M - 1] = true;
                    ans[N - i - 1][M - 1] = true;
                }
            } else {
                for (int i = 0; i < ((N - R - 1) / 2); i++) {
                    ans[i][M - 1] = true;
                    ans[N - i - 1][M - 1] = true;
                }
                ans[(N - 1) / 2][M - 1] = true;
            }
        } else {
            // even - only even C are possible
            if (R % 2 == 1) {
                cout << "IMPOSSIBLE";
                return 0;
            }
            for (int i = 0; i < ((N - R) / 2); i++) {
                ans[i][M - 1] = true;
                ans[N - i - 1][M - 1] = true;
            }
        }
    } else {
        // basic method when interference is not guaranteed

        // messed up on this and did nested to form a rectangle to block off, where I intended only to use a line to block off
        for (int i = R; i < N; i++) {
            ans[i][M - 1] = true;
        }

        for (int i = C; i < M; i++) {
            ans[N - 1][i] = true;
        }

        // part i was missing
        if (R == 0 || C == 0) {
            special = true;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << (special && i == N - 1 && j == M - 1 ? 'c' : (ans[i][j] ? 'b' : 'a'));
        }
        cout << '\n';
    }

    return 0;
}
