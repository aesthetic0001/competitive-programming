#include <bits/stdc++.h>
#include <cstdio>

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

int fentanylSum[100001], fentanylOccurences[100001], original[100001], N, M;

int query(int* fentTree, int idx) {
    int ans = 0;
    while (idx > 0) {
        ans += fentTree[idx];
        idx -= idx & -idx;
    }
    return ans;
}

void update(int* fentTree, int idx, int delta) {
    assert(idx != 0);
    while (idx <= 100000) {
        fentTree[idx] += delta;
        idx += idx & -idx;
    }
}

int query_range(int* fentTree, int l, int r) {
    return query(fentTree, r) - query(fentTree, l - 1);
}

void print_fentwick(int * fentTree) {
    for (int i = 0; i <= N; i++) {
        printf("%lld ", fentTree[i]);
    }
    printf("\n");
}

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif

    scanf("%lld %lld", &N, &M);

    // initialize the fentanyl tree
    for (int i = 1; i <= N; i++) {
        int v; scanf("%lld", &v);
        original[i] = v;
        update(fentanylSum, i, v);
        update(fentanylOccurences, v, 1);
    }

    for (int i = 0; i < M; i++) {
        char c; cin >> c;

        switch (c) {
            case 'C': {
                int idx, x; scanf("%lld %lld", &idx, &x);

                update(fentanylSum, idx, -original[idx] + x);
                update(fentanylOccurences, x, 1);
                update(fentanylOccurences, original[idx], -1);

                original[idx] = x;
                break;
            }
            case 'S': {
                int l, r; scanf("%lld %lld", &l, &r);
                printf("%lld\n", query_range(fentanylSum, l, r));
                break;
            }
            case 'Q': {
                int x; scanf("%lld", &x);
                printf("%lld\n", query_range(fentanylOccurences, 1, x));
                break;
            }
        }
    }

    return 0;
}
