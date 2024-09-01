#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

// y, x
int N;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    while (true) {
        scanf("%d", &N);
        if (N == 0) return 0;
        // x, y
        vector<pair<double, double>> values;
        set<pair<double, double>, greater<pair<double, double>>> st;
        double bestDist = INFINITY;
        pair<pair<double, double>, pair<double, double>> ans;

        for (int j = 0; j < N; j++) {
            double x, y; scanf("%lf %lf", &x, &y);
            values.eb(mp(x, y));
        }

        sort(values.begin(), values.end());

        for (int j = 1; j < sz(values); j++) {
            const auto &[x1, y1] = values[j];
            const auto &[prevX, prevY] = values[j - 1];
            const double dx = x1 - prevX, dy = abs(y1 - prevY), dist = pow(dx, 2) + pow(dy, 2);

            if (dist < bestDist) {
                bestDist = dist;
                ans.first = mp(x1, y1);
                ans.second = mp(prevX, prevY);
            }
            if (dx <= bestDist && dy <= bestDist) {
                st.em(mp(prevY, prevX));
            }

            vector<pair<double, double>> toDelete;

            for (const auto &[y2, x2] : st) {
                const double dx = x1 - x2, dy = abs(y1 - y2), dist = pow(dx, 2) + pow(dy, 2);

                if (dist > bestDist) {
                    toDelete.eb(mp(y2, x2));
                    continue;
                }

                if (dist < bestDist) {
                    bestDist = dist;
                    ans.first = mp(x1, y1);
                    ans.second = mp(x2, y2);
                }
            }

            for (const auto &val : toDelete) {
                st.erase(val);
            }
        }

        printf("%.2lf %.2lf %.2lf %.2lf\n", ans.first.first, ans.first.second, ans.second.first, ans.second.second);
    }

    return 0;
}
