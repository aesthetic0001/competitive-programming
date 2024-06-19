#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

inline double dist2d(double x1, double y1, double x2, double y2) {
    return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    for (int i = 0; i < 10; i++) {
        int T, N, ans = 0;
        // centerX center Y radius
        double bombX, bombY, radius;
        // pair<X, Y> pair<centerX, centerY> speed
        cin >> bombX >> bombY >> radius >> T >> N;

        for (int j = 0; j < N; j++) {
            double X, Y, CX, CY, speed; cin >> X >> Y >> CX >> CY >> speed;
            double zombRadius = dist2d(X, Y, CX, CY);
            double dist = (-speed * T) / zombRadius;
            double rot = atan((Y - CY) / (X - CX)) + dist;

            if (X - CX < 0) {
                rot += M_PI;
            } else if (Y - CY < 0) {
                rot += 2 * M_PI;
            }

            double newX = zombRadius * cos(rot) + CX;
            double newY = zombRadius * sin(rot) + CY;

            if (dist2d(newX, newY, bombX, bombY) <= radius) {
                ++ans;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
