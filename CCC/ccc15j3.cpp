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

unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
string old, ans;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin >> old;

    for (int i = 0; i < sz(old); i++) {
        const auto &c = old[i];
        ans += c;
        if (vowels.find(c) != vowels.end()) continue;

        char best = 'Z';
        for (const auto &v : vowels) {
            int b = abs(static_cast<int>(best) - static_cast<int>(c)), n = abs(static_cast<int>(v) - static_cast<int>(c));
            if ((b == n && v < best)|| b > n) {
                best = v;
            }
        }
        ans += best;

        int next = static_cast<int>(c) + 1;

        while (next < static_cast<int>('z') && vowels.find(static_cast<char>(next)) != vowels.end()) {
            next++;
        }

        ans += static_cast<char>(min(next, static_cast<int>('z')));
    }

    cout << ans;


    return 0;
}
