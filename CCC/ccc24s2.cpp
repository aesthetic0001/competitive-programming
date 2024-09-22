#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int T, N, occurences[27];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin.tie(0); cin.sync_with_stdio(0);

    cin >> T >> N;

    for (int _ = 0; _ < T; _++) {
        string s; cin >> s;
        for (int i = 0; i < N; i++) {
            occurences[s[i] - 'a'] = 0;
        }
        for (int i = 0; i < N; i++) {
            occurences[s[i] - 'a'] += 1;
        }

        bool heavy = occurences[s[0] - 'a'] > 1;
        bool bad = false;
        for (int i = 1; i < N; i++) {
            if ((heavy && occurences[s[i] - 'a'] > 1) || (!heavy && occurences[s[i] - 'a'] == 1)) {
                bad = true;
                cout << "F\n";
                break;
            }
            heavy = occurences[s[i] - 'a'] > 1;
        }

        if (!bad) cout << "T\n";
    }

    return 0;
}
