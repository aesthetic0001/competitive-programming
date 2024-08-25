#include <bits/stdc++.h>

#define int long long

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N, H, P, temp1, ans = INT64_MAX, lvlMax = 0, lvlSum = 0, permCancel = 0;
priority_queue<int, vector<int>, greater<int>> pq;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld %lld %lld", &N, &H, &P);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &temp1);
        lvlSum += temp1;
        lvlMax = max(temp1, lvlMax);
        pq.em(temp1);
    }

    // printf("sum: %lld max: %lld\n", lvlSum, lvlMax);

    // lvlmax is at most 10^6
    for (int x = 0; x <= lvlMax; x++) {
        while (!pq.empty() && x > pq.top()) {
            pq.pop();
        }
        if (x > 0) permCancel += sz(pq);
        const int y = lvlSum - (permCancel);
        ans = min(H * x + P * y, ans);
        // printf("x: %lld y: %lld val: %lld cancel: %lld\n", x, y, H * x + P * y, permCancel);
    }

    printf("%lld\n", ans);

    return 0;
}
