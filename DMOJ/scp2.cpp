#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N;
string s;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    cin.tie(0); cin.sync_with_stdio(0);

    cin >> N;
    cin >> s;

    // check if the whole string is the same thing
    int ct = 0;
    while (s[ct] == s[0]) {
      ct++;
    }
    if (ct == N) {
      cout << 1;
      return 0;
    }

    if (s[0] == s[N - 1]) {
      N -= 1;
    } else {
      cout << N;
      return 0;
    }

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        N -= 1;
      }
    }

    cout << N;

    return 0;
}

