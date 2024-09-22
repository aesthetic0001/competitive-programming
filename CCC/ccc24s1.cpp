#include <bits/stdc++.h>

// #define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define PII pair<int, int>

using namespace std;

int N, A[1000000], ans = 0;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N / 2; i++) {
        if (A[i] == A[i + (N / 2)]) {
            ans += 2;
        }
    }

    printf("%d", ans);

    return 0;
}
