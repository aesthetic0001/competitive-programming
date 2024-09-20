#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, M, A[100000], l = 0, r = 0;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld %lld", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        r += A[i];
        l = max(l, A[i]);
    }

    while (r > l) {
        int mp = (l + r) / 2;
        int sum = 0, subarrays = 1;

        for (int i = 0; i < N; i++) {
            if (sum + A[i] > mp) {
                sum = A[i];
                subarrays += 1;
            } else {
                sum += A[i];
            }
        }

        if (subarrays <= M) {
            r = mp;
        } else {
            l = mp + 1;
        }
    }

    printf("%lld\n", l);

    return 0;
}
