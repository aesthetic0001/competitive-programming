#include <bits/stdc++.h>
#define int long long

using namespace std;

int sx, sy, sz, tx, ty, tz, relx, rely, relz;
int ans;

inline int rel_dist3d(int x, int y, int z) {
    return x * x + y * y + z * z;
}

signed main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin >> sx >> sy >> sz >> tx >> ty >> tz;

    int d;
    char turn;

    relx = tx - sx;
    rely = ty - sy;
    relz = tz - sz;

    ans = rel_dist3d(relx, rely, relz);

    while (true) {
        cin >> d >> turn;

        const int newx = relx - d;

        // diff sign means that it crossed the x axis
        if (newx * relx < 0) {
            ans = min(ans, rel_dist3d(0, rely, relz));
        } else {
            ans = min(ans, rel_dist3d(newx, rely, relz));
        }

        relx = newx;

        switch (turn) {
            case 'L': {
                relx *= -1;
                swap(relx, rely);
                break;
            }
            case 'R': {
                rely *= -1;
                swap(relx, rely);
                break;
            }
            case 'U': {
                relx *= -1;
                swap(relx, relz);
                break;
            }
            case 'D': {
                relz *= -1;
                swap(relx, relz);
                break;
            }
        }

        if (turn == 'E') break;
    }

    cout << fixed << setprecision(2) << sqrt(ans);

    return 0;
}
