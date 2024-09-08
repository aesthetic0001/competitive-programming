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

int t, n;
vector<string> vs, vs2;
string s;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        int mx = 0;

        for (int j = 0; j < n; j++) {
            cin >> s;
            vs2.eb(s);
        }

        vs.eb(vs2[vs2.size() - 1]);

        for (int j = 0; j < n; j++) {
            string &s = vs2[j];
            if (vs.size() >= 2 && vs[vs.size() - 2] == s) vs.pop_back();
            else vs.eb(s);
            mx = max(static_cast<int>(vs.size() - 1), mx);
        }

        cout << (10 * n - mx * 20) << '\n';
        vs.clear(); vs2.clear();
    }

    return 0;
}
