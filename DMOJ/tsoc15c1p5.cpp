#include <bits/stdc++.h>
#include <cstdio>

// if segfaults, try using cstdio (scanf and print) because the buffered input may be tweaking

// #define int long long
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

int N, M, W, temp1, temp2, dist[101], antdist[101];
vector<int> adj[101], ants;
queue<int> q;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    fread(_i,1,INPUT_SIZE,stdin);

    su(N); su(M);

    for (int i = 0; i <= N; i++) {
        dist[i] = INT32_MAX;
        antdist[i] = INT32_MAX;
    }

    for (int i = 0; i < M; i++) {
        su(temp1); su(temp2);
        adj[temp1].eb(temp2);
        adj[temp2].eb(temp1);
    }

    su(W);

    for (int i = 0; i < W; i++) {
        su(temp1);
        ants.eb(temp1);
    }

    for (const int &ant : ants) {
        // printf("start ant: %d\n", ant);
        antdist[ant] = 0;
        q.em(ant);
        while (!q.empty()) {
            const int top = q.front(); q.pop();
            for (const auto &other : adj[top]) {
                if (antdist[other] > antdist[top] + 4) {
                    antdist[other] = antdist[top] + 4;
                    q.em(other);
                }
            }
        }
    }

    // for (int i = 1; i <= N; i++) {
    //     printf("antdist for %d: %d\n", i, antdist[i]);
    // }

    dist[1] = 0;
    q.em(1);

    while (!q.empty()) {
        const int top = q.front(); q.pop();

        for (const auto &other : adj[top]) {
            if (dist[other] > dist[top] + 1 && antdist[other] >= dist[top] + 1) {
                dist[other] = dist[top] + 1;
                q.em(other);
            }
        }
    }

    if (dist[N] == INT32_MAX) {
        printf("sacrifice bobhob314");
    } else {
        printf("%d", dist[N]);
    }

    return 0;
}
