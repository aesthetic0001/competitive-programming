#include <bits/stdc++.h>
#include <cstdint>
#include <cstdio>

#define int long long
#ifdef fread_unlocked
#define fread fread_unlocked
#endif
#define INPUT_SIZE (4<<20)
int _i0=0;
char _i[INPUT_SIZE+5];
#define su(x) do{while((_=_i[_i0++])<48);for(x=_-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si(x) do{while((_n=_i[_i0++])<45);if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
#define su2(x) do{for(x=_i[_i0++]-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)
#define si2(x) do{_n=_i[_i0++];if(_n-45)x=_n;else x=_i[_i0++];for(x-=48;47<(_=_i[_i0++]);x=x*10+_-48);if(_n<46)x=-x;}while(0)
#define ss(x) do{int i=0; while((_=_i[_i0++])<=32); for(; _>32; _= _i[_i0++]) x[i++]=_; x[i]='\0';}while(0)
char _,_n;

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
    fread(_i,1,INPUT_SIZE,stdin);

    su2(N); su2(H); su2(P);

    for (int i = 0; i < N; i++) {
        su2(temp1);
        lvlSum += temp1;
        lvlMax = max(temp1, lvlMax);
        pq.em(temp1);
    }

    // printf("sum: %lld max: %lld\n", lvlSum, lvlMax);

    // lvlmax is at most 10^6
    for (int x = 0; x <= lvlMax; x++) {
        while (x > pq.top()) {
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
