
#include <iostream>
#include <vector>

using namespace std;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int N, T; cin >> N >> T;

    vector<pair<int, int> > trees;
    vector<int> treesX;
    vector<int> treesY;

    trees.emplace_back(0, 0);
    treesX.emplace_back(0);
    treesY.emplace_back(0);

    for (int i = 0; i < T; i++) {
        pair<int, int> t; cin >> t.first >> t.second;
        trees.emplace_back(t);
        treesX.emplace_back(t.first);
        treesY.emplace_back(t.second);
    }

    int ans = 0;

    for (const int &tX : treesX) {
        for (const int &tY : treesY) {
            const int optimalS = min(N - tX, N - tY);
            int bestS = optimalS;
            for (const auto &[otherX, otherY] : trees) {
                // cout << best_s << "\n";
                if (otherX > tX && otherY > tY)  {
                    bestS = min(bestS, max(otherX - tX, otherY - tY));
                }
            }
            ans = max(ans, bestS);
        }
    }

    cout << ans;

    return 0;
}
