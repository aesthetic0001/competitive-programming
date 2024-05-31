#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

signed main() {
    cin.tie(0); cin.sync_with_stdio(0);

    int N, A, C; cin >> N >> A >> C;

    vector<pair<int, int> > ac;

    for (int i = 0; i < A; i++) {
        int s, e; cin >> s >> e;
        ac.emplace_back(make_pair(s - 1, 1));
        ac.emplace_back(make_pair(e, -1));
    }

    for (int i = 0; i < C; i++) {
        int s, e; cin >> s >> e;
        ac.emplace_back(make_pair(s - 1, 2));
        ac.emplace_back(make_pair(e, -2));
    }

    sort(ac.begin(), ac.end());

    int ans = 0;
    int a = 0, c = 0;
    int start = 1;

    for (int i = 0; i < ac.size(); i++) {
        const int t = ac[i].first, action = ac[i].second;

        if (a > 0 && c <= 0) {
            ans += (t - start);
        }

        switch (action) {
            case 1: {
                ++a;
                break;
            }
            case -1: {
                --a;
                break;
            }
            case 2: {
                ++c;
                break;
            }
            case -2: {
                --c;
                break;
            }
        }
        start = t;
    }

    cout << ans;

    return 0;
}
