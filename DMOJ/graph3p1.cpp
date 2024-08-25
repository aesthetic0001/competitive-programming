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

int N, M, K, temp1, temp2, dist[30001], ans = 0;
vector<int> adj[30001];
queue<int> startQ, bfsQ;

signed main() {
    #ifdef LOCAL
    freopen("sample.in","r",stdin);
    #endif
    fread(_i,1,INPUT_SIZE,stdin);

    su(N); su(M);

    for (int i = 1; i <= N; i++) {
        dist[i] = INT32_MAX;
    }

    for (int i = 0; i < M; i++) {
        su(temp1); su(temp2);
        adj[temp1].eb(temp2);
        adj[temp2].eb(temp1);
    }

    su(K);

    for (int i = 0; i < K; i++) {
        su(temp1);
        startQ.em(temp1);
    }

    while (!startQ.empty()) {
        const int start = startQ.front(); startQ.pop();
        dist[start] = 0;
        bfsQ.em(start);
        while (!bfsQ.empty()) {
            const int top = bfsQ.front(); bfsQ.pop();

            for (const auto &neighbor : adj[top]) {
                if (dist[neighbor] > dist[top] + 1) {
                    dist[neighbor] = dist[top] + 1;
                    bfsQ.em(neighbor);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        ans = max(dist[i], ans);
    }

    printf("%d", ans);

    return 0;
}
