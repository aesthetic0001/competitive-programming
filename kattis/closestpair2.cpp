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

int N;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    // x, y
    vector<pair<double, double>> values;
    // y, x
    set<pair<double, double>> st;
    // pair of x y points
    pair<pair<double, double>, pair<double, double>> ans;
    double bestDist = INFINITY;

    while (true) {
        scanf("%d", &N);
        if (N == 0) return 0;

        values.clear();
        st.clear();
        bestDist = INFINITY;

        for (int j = 0; j < N; j++) {
            double x, y; scanf("%lf %lf", &x, &y);
            values.eb(mp(x, y));
        }

        sort(values.begin(), values.end());

        for (int j = 0; j < sz(values); j++) {
            const auto &[x1, y1] = values[j];

            auto lb = st.lower_bound({y1 - sqrt(bestDist), INFINITY});
            auto ub = st.upper_bound({y1 + sqrt(bestDist), INFINITY});

            for (; lb != ub; ++lb) {
                const auto v = *lb;
                double dist = pow(v.second - x1, 2) + pow(v.first - y1, 2);
                if (dist < bestDist) {
                    bestDist = dist;
                    ans.first = mp(v.second, v.first);
                    ans.second = values[j];
                }
            }

            st.em(mp(y1, x1));
        }

        printf("%.2lf %.2lf %.2lf %.2lf\n", ans.first.first, ans.first.second, ans.second.first, ans.second.second);
    }

    return 0;
}
