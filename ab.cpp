#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    int max = 5;
    bool composite[max + 1];
    vector<int> primes;

    for (int i = 0; i < max + 1; i++) {
      composite[i] = false;
    }

    for (int i = 2; i <= max; i++) {
      if (!composite[i]) {
        primes.emplace_back(i);
        for (int j = i; j <= max; j += i) {
          composite[j] = true;
        }
      }
    }

    for (const auto &prime : primes) {
      printf("%d\n", prime);
    }

    return 0;
}

