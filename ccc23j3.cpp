#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int freq[5];

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    int N; scanf("%d", &N);

    for (int i = 0; i < N; i++) {
      string s; cin >> s;
      for (int j = 0; j < 5; j++) {
        char &c = s[j];
        if (c == 'Y') {
          freq[j] += 1;
        }
      }
    }

    vector<int> ans;
    int highest = 0;

    for (int i = 0 ; i < 5; i++) {
      highest = max(freq[i], highest);
    }

    for (int i = 0; i < 5 ; i++) {
      if (freq[i] == highest) {
        ans.emplace_back(i + 1);
      }
    }

    for (int i = 0 ; i < ans.size(); i++) {
      printf("%d", ans[i]);
      if (i != ans.size() - 1) {
        printf(",");
      }
    }

    return 0;
}

