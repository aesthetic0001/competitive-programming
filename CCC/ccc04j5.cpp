#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

// dir: top: 1, right: 2, bottom: 3, left: 4
// dir, xs, xe, ys, ye
int L, W, X, iters = 0; vector<tuple<int, int, int, int, int>> lines, newlines; set<int> ans;

inline void recurse(int level = 0) {
    if (level == L) return;
    lines = std::move(newlines);

    for (const auto &[dir, xs, xe, ys, ye] : lines) {
        // form fractals
        switch (dir) {
            case 1: {
                // top, left, right, and the two other sides formed by the split
                const int third = (xe - xs) / 3;
                newlines.emplace_back(1, xs, xs + third, ys, ys);
                newlines.emplace_back(1, xs + 2 * third, xe, ys, ys);
                newlines.emplace_back(1, xs + third, xs + 2 * third, ys + third, ys + third);

                // left and right
                newlines.emplace_back(4, xs + third, xs + third, ys, ys + third);
                newlines.emplace_back(2, xs + 2 * third, xs + 2 * third, ys, ys + third);
                break;
            }
            case 2: {
                const int third = (ye - ys) / 3;
                newlines.emplace_back(2, xe, xe, ys, ys + third);
                newlines.emplace_back(2, xe, xe, ys + 2 * third, ye);
                newlines.emplace_back(2, xe + third, xe + third, ys + third, ys + 2 * third);

                newlines.emplace_back(1, xe, xe + third, ys + 2 * third, ys + 2 * third);
                newlines.emplace_back(3, xe, xe + third, ys + third, ys + third);
                break;
            }
            case 3: {
                const int third = (xe - xs) / 3;
                newlines.emplace_back(3, xs, xs + third, ys, ys);
                newlines.emplace_back(3, xs + 2 * third, xe, ys, ys);
                newlines.emplace_back(3, xs + third, xs + 2 * third, ys - third, ys - third);

                newlines.emplace_back(4, xs + third, xs + third, ys, ys - third);
                newlines.emplace_back(2, xs + 2 * third, xs + 2 * third, ys, ys - third);
                break;
            }
            case 4: {
                const int third = (ye - ys) / 3;
                newlines.emplace_back(4, xe, xe, ys, ys + third);
                newlines.emplace_back(4, xe, xe, ys + 2 * third, ye);
                newlines.emplace_back(4, xe - third, xe - third, ys + third, ys + 2 * third);

                newlines.emplace_back(1, xe, xe - third, ys + 2 * third, ys + 2 * third);
                newlines.emplace_back(3, xe, xe - third, ys + third, ys + third);
                break;
            }
        }
    }

    return recurse(level + 1);
}

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    cin >> L >> W >> X;

    newlines.emplace_back(1, 0, W, 1, 1);

    recurse();

    for (const auto [dir, xs, xe, ys, ye] : newlines) {
        if (xs == xe && X == xs) {
            // vertical
            // cout << "vertical " << xs << " " << ys << " " << ye << "\n";
            for (int i = ys; i <= ye; i++) {
                ans.insert(i);
            }
        } else {
            // horizontal
            // cout << "horizontal " << ys << " " << xs << " " << xe << "\n";
            if (X <= xe && X >= xs) {
                ans.insert(ys);
            }
        }
    }

    for (const auto &v : ans) cout << v << " ";

    return 0;
}
