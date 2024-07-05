#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

double MAXW, MAXH, INITIAL_X, FIRST_Y;

// pairhash
namespace std {
    template <>
    struct hash<pair<double, double>> {
        size_t operator()(const pair<double, double> &x) const {
            return hash<double>()(x.first) ^ hash<double>()(x.second);
        }
    };
}

// pos x, y
pair<double, double> pos; double slope; bool posX;
unordered_set<pair<double, double>> vis;
int ans = 0;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> MAXW >> MAXH >> INITIAL_X >> FIRST_Y;
    slope = FIRST_Y / (MAXW - INITIAL_X);
    posX = true;

    pos = {INITIAL_X, static_cast<double>(0)};

    while (true) {
        // cout << ans << "\n";
        // cout << "INI POS " << pos.first << " " << pos.second << "\n";
        // cout << slope << "\n";
        // cout << posX << "\n";
        if (vis.find(pos) != vis.end()) {
            // cout << "CYCLE";
            cout << 0;
            return 0;
        }
        if (vis.size() < 4) vis.insert(pos);
        if (posX) {
            // see if it intersects with any of the lines
            // lines: x = 0, x = MAXW, y = 0, y = MAXH
            // cannot intersect x=0 (makes no sense: x is always increasing in posx. cannot go back in x)
            // use the first one which results in an intersection within the bounds of (0, 0) and (MAXW, MAXH)
            // x=maxw

            if (pos.second + slope * (MAXW - pos.first) <= MAXH && pos.second + slope * (MAXW - pos.first) >= 0) {
                // cout << "INTERSECTED WITH X=MAXW\n";
                pos = {MAXW, pos.second + slope * (MAXW - pos.first)};
            } else if (pos.second + (MAXH - pos.second) / slope <= MAXW && pos.second + (MAXH - pos.second) / slope >= 0) {
                // cout << "INTERSECTED WITH Y=MAXH\n";
                pos = {pos.first + (MAXH - pos.second) / slope, MAXH};
            } else {
                // cout << "INTERSECTED WITH Y=0\n";
                pos = {pos.first + (0 - pos.second) / slope, 0};
            }
        } else {
            // see if it intersects with any of the lines
            // lines: x = 0, x = MAXW, y = 0, y = MAXH
            // cannot intersect x=MAXW (makes no sense: x is always decreasing in negx. cannot go forward in x)
            // use the first one which results in an intersection within the bounds of (0, 0) and (MAXW, MAXH)
            // x=0
            if (pos.second + slope * (0 - pos.first) <= MAXH && pos.second + slope * (0 - pos.first) >= 0) {
                // cout << "INTERSECTED WITH X=0\n";
                pos = {0, pos.second + slope * (0 - pos.first)};
            } else if (pos.second + (MAXH - pos.second) / slope <= MAXW && pos.second + (MAXH - pos.second) / slope >= 0) {
                // cout << "INTERSECTED WITH Y=MAXH\n";
                pos = {pos.first + (MAXH - pos.second) / slope, MAXH};
            } else {
                // cout << "INTERSECTED WITH Y=0\n";
                pos = {pos.first + (0 - pos.second) / slope, 0};
            }
        }

        // cout << "POST POS " << pos.first << " " << pos.second << "\n";

        // determine posX or posY depending on current position and sign of slope

        if (pos.first == 0) {
            // cout << "HIT LEFT WALL\n";
            posX = true;
        } else if (pos.first == MAXW) {
            // cout << "HIT RIGHT WALL\n";
            posX = false;
        } else if (pos.second == 0) {
            // cout << "HIT BOTTOM WALL\n";
            // cannot go down in y
            posX = slope > 0;
        } else if (pos.second == MAXH) {
            // cout << "HIT TOP WALL\n";
            posX = slope > 0;
        }

        // see if absorbed by one of the 4 5x5 corner triangles
        // there is some rounding issue, need to fix this later
        if (pos.first + pos.second < 5) {
            // cout << pos.first + pos.second << "\n";
            // cout << "HIT BOTTOM LEFT CORNER\n";
            cout << ans;
            return 0;
        } else if (pos.first + MAXH - pos.second < 5) {
            // cout << "HIT TOP LEFT CORNER\n";
            cout << ans;
            return 0;
        } else if (MAXW - pos.first + pos.second < 5) {
            // cout << "HIT BOTTOM RIGHT CORNER\n";
            cout << ans;
            return 0;
        } else if (MAXW - pos.first + MAXH - pos.second < 5) {
            // cout << "HIT TOP RIGHT CORNER\n";
            cout << ans;
            return 0;
        }

        slope *= -1;

        ++ans;
    }

    cout << ans;

    return 0;
}
