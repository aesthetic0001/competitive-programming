#include <bits/stdc++.h>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N, ans = 0, val = 0, totalDelta = 0, prevPos = 0, furthest = 0;
// position, delta (+- magnitude per unit)
map<int, int> events;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld", &N);

    for (int i = 0 ; i < N; i++) {
        int P, W, D;
        scanf("%lld %lld %lld", &P, &W, &D);
        int start = max(P - D, 0LL), end = min(P + D, 1000000000LL);
        totalDelta -= W;
        val += W * start;
        events[start] += W;
        events[end] += W;
    }

    ans = val;

    for (const auto &[pos, delta] : events) {
        // printf("%lld: delta %lld | best: %lld total: %lld\n", pos, delta, ans, totalDelta);
        val += (pos - prevPos) * totalDelta;
        prevPos = pos;
        totalDelta += delta;
        ans = min(val, ans);
    }

    printf("%lld", ans);

    return 0;
}
