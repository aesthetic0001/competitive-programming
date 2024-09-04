#include <bits/stdc++.h>

// if segfaults, try using cstdio (scanf and print) because the buffered input may be tweaking

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif
#define INPUT_SIZE (4<<20)
int _i0=0;
char _i[INPUT_SIZE+5];
#define su(x) do{for(x=_i[_i0++]-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si(x) do{_n=_i[_i0++];if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
#define ss(x) do{int i=0; while((_=_i[_i0++])<=32); for(; _>32; _= _i[_i0++]) x[i++]=_; x[i]='\0';}while(0)
char _,_n;

#define eb(a) emplace_back(a)
#define em(a) emplace(a)
#define sz(v) (v).size()
#define mp(a, b) make_pair(a, b)
#define PII pair<int, int>

using namespace std;

int N, temp1, temp2, temp3, best = INT64_MAX;
// position, s/m, dist
tuple<int, int, int> friends[200000];

inline int compute(int c) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        const auto [pos, spd, range] = friends[i];
        if (pos == c) {
            ans += 0;
        } else if (pos < c) {
            int offsetC = max(pos, c - range);
            ans += spd * (offsetC - pos);
            // printf("friend %lld: %lld %lld %lld\n", i, pos, range, offsetC);
        } else {
            int offsetC = min(pos, c + range);
            ans += spd * (pos - offsetC);
            // printf("friend %lld: %lld %lld %lld\n", i, pos, range, offsetC);
        }
    }
    // printf("%lld: %lld\n", c, ans);
    best = min(ans, best);
    return ans;
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    // fread(_i,1,INPUT_SIZE,stdin);

    scanf("%lld", &N);

    int L = INT64_MAX, R = 0;

    for (int i = 0; i < N; i++) {
        scanf("%lld %lld %lld", &temp1, &temp2, &temp3);
        L = min(temp1, L);
        R = max(temp1, R);
        friends[i] = {temp1, temp2, temp3};
    }

    while (R >= L) {
        int midpoint = ceil((R + L) / 2);
        // printf("mp: %lld l: %lld r: %lld\n", midpoint, L, R);
        // left side > right side: pick right side
        if (compute(midpoint) >= compute(midpoint + 1)) {
            // printf("pick right\n");
            L = midpoint + 1;
        } else {
            // printf("pick left\n");
            R = midpoint - 1;
        }
    }

    printf("%lld %lld\n", L, R);

    compute(L);

    printf("%lld", best);

    return 0;
}
