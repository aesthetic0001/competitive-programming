    #include <bits/stdc++.h>

    #define int long long
    #ifdef fread_unlocked
    #define fread fread_unlocked
    #endif

    #define PII pair<int, int>

    using namespace std;

    int N, K, l = 0, r = 2000000000;

    signed main() {
        #ifdef LOCAL
        freopen("sample.in","r",stdin);
        #endif

        scanf("%lld %lld", &N, &K);

        int a[N];

        for (int i = 0; i < N; i++) {
            scanf("%lld", &a[i]);
        }

        sort(a, a + (sizeof(a) / sizeof(a[0])));

        while (r > l) {
            int mp = l + (r - l + 1) / 2, operations = 0;

            for (int i = (N - 1) / 2; i < N; i++) {
                operations += max(0ll, mp - a[i]);
            }

            if (operations <= K) {
                l = mp;
            } else {
                r = mp - 1;
            }
        }

        printf("%lld", l);

        return 0;
    }
